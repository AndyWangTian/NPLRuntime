#pragma once

// events in ParaEngine
namespace ParaEngine
{
	/** Used in event binding. 
	One can also use the configuration manager to alter the default binding.
	see EventBinding.h */
	enum Event_Mapping{
		EM_NONE,
		//player control
		EM_PL_FORWARD,
		EM_PL_BACKWARD,
		EM_PL_LEFT,
		EM_PL_RIGHT,
		EM_PL_SHIFTLEFT,
		EM_PL_SHIFTRIGHT,
		EM_PL_JUMP,
		EM_PL_CROUCH,
		EM_PL_TOGGLE_ALWAYS_RUN,
		EM_PL_TOGGLE_RUN_WALK,
		EM_PL_MOUNT_ON,
		EM_PL_ACTION1,
		EM_PL_ACTION2,
		EM_PL_ACTION3,
		EM_PL_ACTION4,
		//game control
		EM_GM_PAUSE,
		EM_GM_NEXTANIM,
		EM_GM_PRIORANIM,
		EM_GM_NEXTOBJ,

		//camera control
		EM_CAM_LOCK,
		EM_CAM_RESET,
		EM_CAM_MODE_FOLLOW,
		EM_CAM_MODE_FREE,
		EM_CAM_FOCUS_POS_UP,
		EM_CAM_FOCUS_POS_DOWN,
		EM_CAM_FORWARD,
		EM_CAM_BACKWARD,
		EM_CAM_LEFT,
		EM_CAM_RIGHT,
		EM_CAM_SHIFTLEFT,
		EM_CAM_SHIFTRIGHT,
		EM_CAM_LEFTDOWN,
		EM_CAM_LEFTUP,
		EM_CAM_RIGHTDOWN,
		EM_CAM_RIGHTUP,
		EM_CAM_ZOOM, // mouse wheel 
		EM_CAM_ZOOM_IN,
		EM_CAM_ZOOM_OUT,

		//GUI control events
		EM_CTRL_CHANGE,
		EM_CTRL_MODIFY,
		EM_CTRL_CHAR,
		EM_CTRL_KEYDOWN,
		EM_CTRL_KEYUP,
		EM_CTRL_HOLDKEY,
		EM_CTRL_SELECT,
		EM_CTRL_FOCUSIN,
		EM_CTRL_FOCUSOUT,
		EM_CTRL_FRAMEMOVE,
		EM_CTRL_UPDATEKEY,
		EM_CTRL_CAPTUREMOUSE,
		EM_CTRL_RELEASEMOUSE,
		EM_CTRL_NEXTKEYFOCUS,

		//GUI button events
		EM_BTN_DOWN,
		EM_BTN_UP,
		EM_BTN_CLICK,

		//GUI scrollbar events
		EM_SB_ACTIONEND,
		EM_SB_ACTIONBEGIN,
		EM_SB_PAGEDOWN,
		EM_SB_PAGEUP,
		EM_SB_STEPDOWN,
		EM_SB_STEPUP,
		EM_SB_SCROLL,

		//GUI EditBox Events
		EM_EB_SELECTSTART,
		EM_EB_SELECTEND,
		EM_EB_SELECTALL,

		//GUI IMEEditBox events
		EM_IME_SELECT,

		//GUI ListBox events
		EM_LB_ACTIONEND,
		EM_LB_ACTIONBEGIN,

		//GUI Slider events
		EM_SL_ACTIONBEGIN,
		EM_SL_ACTIONEND,
		EM_SL_CHANGEVALUE,

		//GUI Canvas events
		EM_CV_ROTATEBEGIN,
		EM_CV_ROTATEEND,
		EM_CV_PANBEGIN,
		EM_CV_PANEND,

		//virtual keys
		EM_KEY_BEGIN,
		EM_KEY_BACKSPACE=EM_KEY_BEGIN,
		EM_KEY_TAB,
		EM_KEY_RETURN,
		EM_KEY_SHIFT,
		EM_KEY_CONTROL,
		EM_KEY_ALT,
		EM_KEY_PAUSE,
		EM_KEY_CAPSLOCK,
		EM_KEY_ESCAPE,
		EM_KEY_SPACE,
		EM_KEY_PAGE_DOWN,
		EM_KEY_PAGE_UP,
		EM_KEY_END,
		EM_KEY_HOME,
		EM_KEY_LEFT,
		EM_KEY_UP,
		EM_KEY_RIGHT,
		EM_KEY_DOWN,
		EM_KEY_PRINT,
		EM_KEY_INSERT,
		EM_KEY_DELETE,
		EM_KEY_HELP,
		EM_KEY_WIN_WINDOW,
		EM_KEY_WIN_LWINDOW,
		EM_KEY_WIN_RWINDOW,
		EM_KEY_WIN_APPS,
		EM_KEY_NUMPAD_BEGIN,
		EM_KEY_NUMPAD0=EM_KEY_NUMPAD_BEGIN,
		EM_KEY_UPNUMPAD0,//insert
		EM_KEY_NUMPAD1,
		EM_KEY_UPNUMPAD1,//end
		EM_KEY_NUMPAD2,
		EM_KEY_UPNUMPAD2,//down
		EM_KEY_NUMPAD3,
		EM_KEY_UPNUMPAD3,//page down
		EM_KEY_NUMPAD4,
		EM_KEY_UPNUMPAD4,//left
		EM_KEY_NUMPAD5,
		EM_KEY_UPNUMPAD5,//nothing
		EM_KEY_NUMPAD6,
		EM_KEY_UPNUMPAD6,//right
		EM_KEY_NUMPAD7,
		EM_KEY_UPNUMPAD7,//home
		EM_KEY_NUMPAD8,
		EM_KEY_UPNUMPAD8,//up
		EM_KEY_NUMPAD9,
		EM_KEY_UPNUMPAD9,//page up
		EM_KEY_MULTIPLY,
		EM_KEY_ADD,
		EM_KEY_SEPARATOR,
		EM_KEY_SUBTRACT,
		EM_KEY_DECIMAL,
		EM_KEY_UPDECIMAL,//delete
		EM_KEY_DIVIDE,
		EM_KEY_NUMPADENTER,
		EM_KEY_NUMPADEQUALS,
		EM_KEY_NUMPAD_END=EM_KEY_NUMPADEQUALS,
		EM_KEY_F1,
		EM_KEY_F2,
		EM_KEY_F3,
		EM_KEY_F4,
		EM_KEY_F5,
		EM_KEY_F6,
		EM_KEY_F7,
		EM_KEY_F8,
		EM_KEY_F9,
		EM_KEY_F10,
		EM_KEY_F11,
		EM_KEY_F12,
		EM_KEY_F13,
		EM_KEY_F14,
		EM_KEY_F15,
		EM_KEY_NUMLOCK,
		EM_KEY_SCROLLLOCK,
		EM_KEY_LSHIFT,
		EM_KEY_RSHIFT,
		EM_KEY_LCONTROL,
		EM_KEY_RCONTROL,
		EM_KEY_LALT,
		EM_KEY_RALT,
		EM_KEY_TEXT_BEGIN,
		EM_KEY_TILDE=EM_KEY_TEXT_BEGIN,//'`'
		EM_KEY_UPTILDE,//'~'
		EM_KEY_MINUS,//'-'
		EM_KEY_UPMINUS,//'_'
		EM_KEY_EQUALS,//'='
		EM_KEY_UPEQUALS,//'+'
		EM_KEY_LBRACKET,//'['
		EM_KEY_UPLBRACKET,//'{'
		EM_KEY_RBRACKET,//']'
		EM_KEY_UPRBRACKET,//'}'
		EM_KEY_BACKSLASH,//'\'
		EM_KEY_UPBACKSLASH,//'|'
		EM_KEY_SEMICOLON,//';'
		EM_KEY_UPSEMICOLON,//':'
		EM_KEY_APOSTROPHE,//'''
		EM_KEY_UPAPOSTROPHE,//'"'
		EM_KEY_GRAVE,
		EM_KEY_UPGRAVE,
		EM_KEY_COMMA,//','
		EM_KEY_UPCOMMA,//'<'
		EM_KEY_PERIOD,//'.'
		EM_KEY_UPPERIOD,//'>'
		EM_KEY_SLASH,//'/'
		EM_KEY_UPSLASH,//'?'
		EM_KEY_0,
		EM_KEY_UP0,//')'
		EM_KEY_1,
		EM_KEY_UP1,//'!'
		EM_KEY_2,
		EM_KEY_UP2,//'@'
		EM_KEY_3,
		EM_KEY_UP3,//'#'
		EM_KEY_4,
		EM_KEY_UP4,//'$'
		EM_KEY_5,
		EM_KEY_UP5,//'%'
		EM_KEY_6,
		EM_KEY_UP6,//'^'
		EM_KEY_7,
		EM_KEY_UP7,//'&'
		EM_KEY_8,
		EM_KEY_UP8,//'*'
		EM_KEY_9,
		EM_KEY_UP9,//'('
		EM_KEY_Z,
		EM_KEY_UPZ,
		EM_KEY_Y,
		EM_KEY_UPY,
		EM_KEY_X,
		EM_KEY_UPX,
		EM_KEY_W,
		EM_KEY_UPW,
		EM_KEY_V,
		EM_KEY_UPV,
		EM_KEY_U,
		EM_KEY_UPU,
		EM_KEY_T,
		EM_KEY_UPT,
		EM_KEY_S,
		EM_KEY_UPS,
		EM_KEY_R,
		EM_KEY_UPR,
		EM_KEY_Q,
		EM_KEY_UPQ,
		EM_KEY_P,
		EM_KEY_UPP,
		EM_KEY_O,
		EM_KEY_UPO,
		EM_KEY_N,
		EM_KEY_UPN,
		EM_KEY_M,
		EM_KEY_UPM,
		EM_KEY_L,
		EM_KEY_UPL,
		EM_KEY_K,
		EM_KEY_UPK,
		EM_KEY_J,
		EM_KEY_UPJ,
		EM_KEY_I,
		EM_KEY_UPI,
		EM_KEY_H,
		EM_KEY_UPH,
		EM_KEY_G,
		EM_KEY_UPG,
		EM_KEY_F,
		EM_KEY_UPF,
		EM_KEY_E,
		EM_KEY_UPE,
		EM_KEY_D,
		EM_KEY_UPD,
		EM_KEY_C,
		EM_KEY_UPC,
		EM_KEY_B,
		EM_KEY_UPB,
		EM_KEY_A,
		EM_KEY_UPA,
		EM_KEY_TEXT_END=EM_KEY_UPA,
		EM_KEY,//any key
		//virtual mouse 
		EM_MOUSE_BEGIN,
		EM_MOUSE_LEFTDOWN=EM_MOUSE_BEGIN,
		EM_MOUSE_LEFTUP,
		EM_MOUSE_LEFTCLICK,
		EM_MOUSE_LEFTDBCLICK,
		EM_MOUSE_RIGHTDOWN,
		EM_MOUSE_RIGHTUP,
		EM_MOUSE_RIGHTCLICK,
		EM_MOUSE_RIGHTDBCLICK,
		EM_MOUSE_MIDDLEDOWN,
		EM_MOUSE_MIDDLEUP,
		EM_MOUSE_MIDDLECLICK,
		EM_MOUSE_MIDDLEDBCLICK,
		EM_MOUSE_LEFTDRAGBEGIN,
		EM_MOUSE_LEFTDRAGEND,
		EM_MOUSE_RIGHTDRAGBEGIN,
		EM_MOUSE_RIGHTDRAGEND,
		EM_MOUSE_MIDDLEDRAGBEGIN,
		EM_MOUSE_MIDDLEDRAGEND,
		EM_MOUSE_DRAGBEGIN,
		EM_MOUSE_DRAGOVER,
		EM_MOUSE_DRAGEND,
		EM_MOUSE_MOVE,
		EM_MOUSE_HOVER,
		EM_MOUSE_WHEEL,
		EM_MOUSE_ENTER,
		EM_MOUSE_LEAVE,
		EM_MOUSE_DOWN,
		EM_MOUSE_UP,
		EM_MOUSE_CLICK,
		EM_MOUSE_DBCLICK,
		EM_MOUSE_LEFT,
		EM_MOUSE_RIGHT,
		EM_MOUSE_MIDDLE,
		EM_MOUSE,
		//container or window event
		EM_WM_SIZE,
		EM_WM_SHOWWINDOW,// The WM_SHOWWINDOW message is sent to a window when the window is about to be hidden or shown.
		EM_WM_CLOSE,
		EM_WM_DESTROY,
		EM_WM_ACTIVATE, // The framework calls this member function when a root level CGUIContainer object is being activated or deactivated
		// the framework call this whenever the render is being called. 
		EM_ONRENDER, 
		EM_TOUCH,
		EM_TOUCH_ENTER,
		EM_TOUCH_DOWN,
		EM_TOUCH_UPDATE,
		EM_TOUCH_UP,
		EM_TOUCH_LEAVE,

		EM_WM_OWNER_DRAW,
		EM_WM_INPUT_METHOD,

		EM_UNKNOWN=0xffff
	};
	enum Editor_events
	{
		ED_SELECTION_CHANGED = 0,
		ED_OBJECT_DELETED,
		ED_OBJECT_CREATED,
		ED_OBJECT_MODIFIED,
		ED_SCENE_LOADED,
		ED_SCENE_UNLOADED,
		ED_SCENE_SAVING,
		ED_SCENE_SAVED,
	};
}