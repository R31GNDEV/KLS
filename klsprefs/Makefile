TARGET := iphone:clang:14.5:12.0
THEOS_PACKAGE_SCHEME = rootless

include $(THEOS)/makefiles/common.mk

BUNDLE_NAME = klsprefs

klsprefs_FILES = KLSRootListController.m
klsprefs_FRAMEWORKS = UIKit
klsprefs_PRIVATE_FRAMEWORKS = Preferences
klsprefs_INSTALL_PATH = /Library/PreferenceBundles
klsprefs_CFLAGS = -fobjc-arc
klsprefs_LIBRARIES = colorpicker
klsprefs_EXTRA_FRAMEWORKS = Cephei CepheiPrefs

include $(THEOS_MAKE_PATH)/bundle.mk
