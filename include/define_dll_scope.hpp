//
// Created by Andrei on 11/03/2021.
//

#ifndef KEY_EVENT_HANDLER_DEFINE_DLL_SCOPE_HPP
#define KEY_EVENT_HANDLER_DEFINE_DLL_SCOPE_HPP

#undef mDLLIMPORTEXPORT
#ifdef WIN32
#ifdef mKEY_PRESS_WATCHER
#define mDLLIMPORTEXPORT __declspec(dllexport)
#else
#define mDLLIMPORTEXPORT __declspec(dllimport)
#endif
#else
#define mDLLIMPORTEXPORT
#endif

#endif //KEY_EVENT_HANDLER_DEFINE_DLL_SCOPE_HPP
