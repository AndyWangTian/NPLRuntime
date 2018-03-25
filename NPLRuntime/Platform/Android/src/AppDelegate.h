#pragma once
#include <android_native_app_glue.h>
#include <EGL/egl.h>
#include "RenderDeviceOpenGL.h"
#include "EventClasses.h"
#include "Framework/InputSystem/VirtualKey.h"
namespace ParaEngine
{
	class CParaEngineAppAndroid;
	class IRenderDevice;
	class IRenderContext;
	class IRenderWindow;
    class AppDelegate 
    {
    public:
        AppDelegate();
		AppDelegate(const std::string& intent_data);
        ~AppDelegate();
        void Run(android_app* app);
    private:
        struct android_app* m_State;
        static void app_handle_command(struct android_app* app, int32_t cmd);
        static int32_t app_handle_input(struct android_app* app, AInputEvent* event);
		static int32_t handle_key_input(AppDelegate* app, AInputEvent* event);
		static void handle_touch_input(AppDelegate* app, AInputEvent* event);
    protected:
        // App commands
        virtual void OnStart();
        virtual void OnStop();
        virtual void OnPause();
        virtual void OnResume();
        virtual void OnDestroy();
        virtual void OnInitWindow();
        virtual void OnTermWindow();
        virtual void OnWindowResized();
		virtual void OnTouch(const std::vector<TouchEventPtr>& events);
		virtual void OnKey(const EVirtualKey& key, const EKeyState& state);

	protected:
		CParaEngineAppAndroid* m_ParaEngineApp;
		bool m_isPaused;
		std::string m_intent_data;
    };


	struct saved_state
	{
		ParaEngine::AppDelegate* app;
	};

}