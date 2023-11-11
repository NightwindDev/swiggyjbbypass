export TARGET := iphone:clang:latest:15.0
export ARCHS = arm64 arm64e
export SYSROOT = $(THEOS)/sdks/iPhoneOS14.4.sdk/

INSTALL_TARGET_PROCESSES = swiggy

include $(THEOS)/makefiles/common.mk

TWEAK_NAME = SwiggyJBBypass

SwiggyJBBypass_FILES = Tweak.x
SwiggyJBBypass_CFLAGS = -fobjc-arc

include $(THEOS_MAKE_PATH)/tweak.mk
