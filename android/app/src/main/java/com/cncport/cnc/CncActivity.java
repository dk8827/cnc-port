package com.cncport.cnc;

import android.annotation.TargetApi;
import android.content.res.AssetManager;
import android.os.Build;
import android.os.Bundle;
import android.os.SystemClock;
import android.util.Log;
import android.view.KeyEvent;
import android.view.View;
import android.view.Window;
import android.view.WindowInsets;
import android.view.WindowInsetsController;
import android.view.WindowManager;
import android.window.OnBackInvokedCallback;
import android.window.OnBackInvokedDispatcher;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import org.libsdl.app.SDLActivity;

public class CncActivity extends SDLActivity {
    private static final String TAG = "CncActivity";
    private static final String ASSET_ROOT = "cnc";

    @Override
    protected String[] getLibraries() {
        return new String[] {"SDL2", "main"};
    }

    @Override
    protected String getMainFunction() {
        return "SDL_main";
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        configureImmersiveMode();
        extractBundledAssets();
        super.onCreate(savedInstanceState);
        registerBackCallback();
        configureImmersiveMode();
    }

    @Override
    protected void onResume() {
        super.onResume();
        configureImmersiveMode();
    }

    @Override
    public void onWindowFocusChanged(boolean hasFocus) {
        super.onWindowFocusChanged(hasFocus);
        if (hasFocus) {
            configureImmersiveMode();
        }
    }

    private void registerBackCallback() {
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.TIRAMISU) {
            registerOnBackInvokedCallback();
        }
    }

    @TargetApi(Build.VERSION_CODES.TIRAMISU)
    private void registerOnBackInvokedCallback() {
        getOnBackInvokedDispatcher().registerOnBackInvokedCallback(
            OnBackInvokedDispatcher.PRIORITY_DEFAULT,
            new OnBackInvokedCallback() {
                @Override
                public void onBackInvoked() {
                    sendEscapePulse();
                }
            }
        );
    }

    private void configureImmersiveMode() {
        Window window = getWindow();
        window.addFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN);
        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.P) {
            WindowManager.LayoutParams attributes = window.getAttributes();
            attributes.layoutInDisplayCutoutMode = WindowManager.LayoutParams.LAYOUT_IN_DISPLAY_CUTOUT_MODE_SHORT_EDGES;
            window.setAttributes(attributes);
        }

        View decorView = window.getDecorView();
        decorView.setSystemUiVisibility(
            View.SYSTEM_UI_FLAG_FULLSCREEN
                | View.SYSTEM_UI_FLAG_HIDE_NAVIGATION
                | View.SYSTEM_UI_FLAG_IMMERSIVE_STICKY
                | View.SYSTEM_UI_FLAG_LAYOUT_FULLSCREEN
                | View.SYSTEM_UI_FLAG_LAYOUT_HIDE_NAVIGATION
                | View.SYSTEM_UI_FLAG_LAYOUT_STABLE
        );

        if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.R) {
            window.setDecorFitsSystemWindows(false);
            WindowInsetsController controller = decorView.getWindowInsetsController();
            if (controller != null) {
                controller.setSystemBarsBehavior(WindowInsetsController.BEHAVIOR_SHOW_TRANSIENT_BARS_BY_SWIPE);
                controller.hide(WindowInsets.Type.statusBars() | WindowInsets.Type.navigationBars());
            }
        }
    }

    @Override
    public void onBackPressed() {
        sendEscapePulse();
    }

    @Override
    public boolean dispatchKeyEvent(KeyEvent event) {
        if (event.getKeyCode() == KeyEvent.KEYCODE_BACK) {
            KeyEvent escapeEvent = new KeyEvent(
                event.getDownTime(),
                event.getEventTime(),
                event.getAction(),
                KeyEvent.KEYCODE_ESCAPE,
                event.getRepeatCount(),
                event.getMetaState(),
                event.getDeviceId(),
                event.getScanCode(),
                event.getFlags(),
                event.getSource()
            );
            super.dispatchKeyEvent(escapeEvent);
            return true;
        }
        return super.dispatchKeyEvent(event);
    }

    private void sendEscapePulse() {
        long now = SystemClock.uptimeMillis();
        dispatchKeyEvent(new KeyEvent(now, now, KeyEvent.ACTION_DOWN, KeyEvent.KEYCODE_ESCAPE, 0));
        dispatchKeyEvent(new KeyEvent(now, now, KeyEvent.ACTION_UP, KeyEvent.KEYCODE_ESCAPE, 0));
    }

    private void extractBundledAssets() {
        File resourceRoot = new File(getFilesDir(), "cnc-root");
        File config = new File(resourceRoot, "assets/cnc/gdi/INSTALL/CONQUER.INI");
        if (config.isFile()) {
            return;
        }

        File target = new File(resourceRoot, "assets/cnc");
        deleteTree(target);
        try {
            copyAssetTree(getAssets(), ASSET_ROOT, target);
        } catch (IOException exception) {
            throw new IllegalStateException("Unable to extract bundled Command & Conquer assets", exception);
        }

        if (!config.isFile()) {
            throw new IllegalStateException("Bundled Command & Conquer assets are missing gdi/INSTALL/CONQUER.INI");
        }
        Log.i(TAG, "Extracted bundled Command & Conquer assets to " + target);
    }

    private static void copyAssetTree(AssetManager assets, String assetPath, File target) throws IOException {
        String[] children = assets.list(assetPath);
        if (children != null && children.length > 0) {
            if (!target.isDirectory() && !target.mkdirs()) {
                throw new IOException("Unable to create directory " + target);
            }
            for (String child : children) {
                copyAssetTree(assets, assetPath + "/" + child, new File(target, child));
            }
            return;
        }

        File parent = target.getParentFile();
        if (parent != null && !parent.isDirectory() && !parent.mkdirs()) {
            throw new IOException("Unable to create directory " + parent);
        }

        byte[] buffer = new byte[1024 * 64];
        try (InputStream input = assets.open(assetPath); OutputStream output = new FileOutputStream(target)) {
            int read;
            while ((read = input.read(buffer)) != -1) {
                output.write(buffer, 0, read);
            }
        }
    }

    private static void deleteTree(File path) {
        if (!path.exists()) {
            return;
        }
        File[] children = path.listFiles();
        if (children != null) {
            for (File child : children) {
                deleteTree(child);
            }
        }
        if (!path.delete()) {
            Log.w(TAG, "Unable to delete " + path);
        }
    }
}
