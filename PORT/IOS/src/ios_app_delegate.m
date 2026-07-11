#import <UIKit/UIKit.h>
#import <objc/runtime.h>

#include <stdio.h>
#include <stdlib.h>

#import "SDL_uikitappdelegate.h"

@interface CncIOSDelegate : SDLUIKitDelegate
@end

@interface SDLUIKitDelegate (CncPrivate)
- (void)postFinishLaunch;
@end

static NSString *CncGetAppDelegateClassName(id self, SEL selector)
{
	return @"CncIOSDelegate";
}

static void CncOrientationDebug(char const *message)
{
	if (getenv("CNC_IOS_ORIENTATION_DEBUG")) {
		fprintf(stderr, "CNC_IOS_ORIENTATION: %s\n", message);
		NSLog(@"CNC_IOS_ORIENTATION: %s", message);
	}
}

static void CncOrientationState(NSString *stage, UIWindowScene *window_scene)
{
	if (getenv("CNC_IOS_ORIENTATION_DEBUG")) {
		NSLog(@"CNC_IOS_ORIENTATION: %@ scene=%ld device=%ld", stage,
			(long)window_scene.interfaceOrientation, (long)[UIDevice currentDevice].orientation);
	}
}

@implementation CncIOSDelegate

+ (void)load
{
	Class meta_class = object_getClass([SDLUIKitDelegate class]);
	Method method = class_getClassMethod([SDLUIKitDelegate class], @selector(getAppDelegateClassName));
	char const *types = method ? method_getTypeEncoding(method) : "@@:";
	class_replaceMethod(meta_class, @selector(getAppDelegateClassName), (IMP)CncGetAppDelegateClassName, types);
	CncOrientationDebug("installed delegate class override");
}

- (void)cnc_requestLandscapeGeometry
{
	if (@available(iOS 16.0, *)) {
		UIWindowScene *window_scene = nil;
		UIWindow *window = [self window];
		if ([window respondsToSelector:@selector(windowScene)]) {
			window_scene = window.windowScene;
		}
		if (!window_scene) {
			for (UIScene *scene in [UIApplication sharedApplication].connectedScenes) {
				if ([scene isKindOfClass:[UIWindowScene class]] && scene.activationState != UISceneActivationStateUnattached) {
					window_scene = (UIWindowScene *)scene;
					break;
				}
			}
		}
		if (!window_scene) {
			CncOrientationDebug("no window scene for landscape request");
			return;
		}
		CncOrientationState(@"before geometry request", window_scene);

		UIWindowSceneGeometryPreferencesIOS *preferences =
			[[UIWindowSceneGeometryPreferencesIOS alloc] initWithInterfaceOrientations:UIInterfaceOrientationMaskLandscape];
		[window_scene requestGeometryUpdateWithPreferences:preferences errorHandler:^(NSError *error) {
			NSLog(@"CNC_IOS_ORIENTATION: landscape geometry request failed: %@", error);
		}];
		[preferences release];

		for (UIWindow *scene_window in window_scene.windows) {
			[scene_window.rootViewController setNeedsUpdateOfSupportedInterfaceOrientations];
		}
	} else {
		[UIViewController attemptRotationToDeviceOrientation];
	}
}

- (UIInterfaceOrientationMask)application:(UIApplication *)application supportedInterfaceOrientationsForWindow:(UIWindow *)window
{
	return UIInterfaceOrientationMaskLandscape;
}

- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions
{
	CncOrientationDebug("CncIOSDelegate didFinishLaunching");
	BOOL launched = [super application:application didFinishLaunchingWithOptions:launchOptions];
	[self cnc_requestLandscapeGeometry];
	return launched;
}

- (void)applicationDidBecomeActive:(UIApplication *)application
{
	CncOrientationDebug("CncIOSDelegate didBecomeActive");
	[self cnc_requestLandscapeGeometry];
}

- (void)postFinishLaunch
{
	CncOrientationDebug("CncIOSDelegate postFinishLaunch");
	[self cnc_requestLandscapeGeometry];
	[super postFinishLaunch];
}

@end
