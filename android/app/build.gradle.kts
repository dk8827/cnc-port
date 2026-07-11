import org.gradle.api.GradleException
import org.gradle.api.tasks.Sync

plugins {
    id("com.android.application")
}

val repoRoot = rootProject.projectDir.parentFile ?: rootProject.projectDir
val localCncAssets = repoRoot.resolve("assets/cnc")
val generatedDebugAssets = layout.buildDirectory.dir("generated/debugAssets")
val generatedDebugAssetsDir = layout.buildDirectory.dir("generated/debugAssets").get().asFile

android {
    namespace = "com.cncport.cnc"
    compileSdk = 36
    ndkVersion = "28.2.13676358"

    defaultConfig {
        applicationId = "com.cncport.cnc"
        minSdk = 23
        targetSdk = 36
        versionCode = 1
        versionName = "0.1-debug"

        ndk {
            abiFilters += "arm64-v8a"
        }

        externalNativeBuild {
            cmake {
                arguments += listOf("-DANDROID_STL=c++_shared")
            }
        }
    }

    sourceSets {
        getByName("main") {
            java.setSrcDirs(
                listOf(
                    "src/main/java",
                    "../third_party/SDL/android-project/app/src/main/java"
                )
            )
        }
        getByName("debug") {
            assets.setSrcDirs(listOf(generatedDebugAssetsDir))
        }
    }

    externalNativeBuild {
        cmake {
            path = file("CMakeLists.txt")
        }
    }

    packaging {
        jniLibs {
            useLegacyPackaging = true
        }
    }
}

val prepareDebugCncAssets = tasks.register<Sync>("prepareDebugCncAssets") {
    group = "build"
    description = "Copies local ignored Command & Conquer assets into debug APK assets for assembleDebug."
    from(localCncAssets)
    into(generatedDebugAssets.map { it.dir("cnc") })

    doFirst {
        val config = localCncAssets.resolve("gdi/INSTALL/CONQUER.INI")
        if (!config.isFile) {
            throw GradleException(
                "Missing local Command & Conquer assets at ${localCncAssets}. " +
                    "Run scripts/prepare_assets_from_local.sh before assembleDebug."
            )
        }
    }
}

tasks.matching { it.name == "mergeDebugAssets" }.configureEach {
    dependsOn(prepareDebugCncAssets)
}

tasks.register("printDebugApkPath") {
    doLast {
        println(layout.buildDirectory.file("outputs/apk/debug/app-debug.apk").get().asFile.absolutePath)
    }
}
