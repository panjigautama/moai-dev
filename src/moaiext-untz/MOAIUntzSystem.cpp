// Copyright (c) 2010-2011 Zipline Games, Inc. All Rights Reserved.
// http://getmoai.com

#include <moaiext-untz/MOAIUntzSystem.h>

//================================================================//
// local
//================================================================//

//----------------------------------------------------------------//
// TODO: doxygen
int MOAIUntzSystem::_getDeviceCount ( lua_State* L ) {
	
	//UInt32 deviceCount = UNTZ::System::get ()->getDeviceCount ();
	//lua_pushnumber ( L, deviceCount );
	
	return 1;
}

//----------------------------------------------------------------//
// TODO: doxygen
int MOAIUntzSystem::_getDeviceInfo ( lua_State* L ) {
	USLuaState state ( L );
	
	//u32 deviceIndex = state.GetValue ( 1, 0 );
	//UNTZ::DeviceInfo info = UNTZ::System::get ()->getDeviceInfo ( deviceIndex );
	//
	//lua_pushstring ( L, info.name.c_str ());
	//lua_pushnumber ( L, info.numInputChannels );
	//lua_pushnumber ( L, info.numOutputChannels );
	
	return 3;
}

//----------------------------------------------------------------//
// TODO: doxygen
int MOAIUntzSystem::_getOptions ( lua_State* L ) {

	//UInt32 options = UNTZ::System::get ()->getOptions ();
	//lua_pushnumber ( L, options );
	
	return 1;
}

//----------------------------------------------------------------//
// TODO: doxygen
int MOAIUntzSystem::_getSampleRate ( lua_State* L ) {
	USLuaState state ( L );
	
	UInt32 sampleRate = UNTZ::System::get ()->getSampleRate ();
	lua_pushnumber ( L, sampleRate );
	
	return 1;
}

//----------------------------------------------------------------//
// TODO: doxygen
int MOAIUntzSystem::_getSupportedFormats ( lua_State* L ) {
	USLuaState state ( L );
	
	//RStringArray& formats = UNTZ::System::get ()->getSupportedFormats ();
	//
	//lua_newtable ( L );
	//for ( RStringArray::size_type i = 0; i < formats.size (); ++i ) {
	//	lua_pushboolean ( L, true );
	//	lua_setfield ( L, -2, formats [ i ].c_str ());
	//}
	return 1;
}

//----------------------------------------------------------------//
// TODO: doxygen
int MOAIUntzSystem::_initialize ( lua_State* L ) {
	USLuaState state ( L );
	
	u32 sampleRate = state.GetValue ( 1, DEFAULT_SAMPLE_RATE );
	u32 numFrames = state.GetValue ( 2, DEFAULT_FRAMES_PER_BUFFER );
	u32 options = state.GetValue ( 3, DEFAULT_OPTIONS );
	
	UNTZ::System::get ()->initialize ( sampleRate, numFrames, options );
	
	return 0;
}

//----------------------------------------------------------------//
// TODO: doxygen
int MOAIUntzSystem::_setInputDevice ( lua_State* L ) {
	USLuaState state ( L );
	
	//u32 deviceIndex = state.GetValue ( 1, 0 );
	//UNTZ::System::get ()->setInputDevice ( deviceIndex );
	
	return 0;
}

//----------------------------------------------------------------//
// TODO: doxygen
int MOAIUntzSystem::_setOptions ( lua_State* L ) {
	USLuaState state ( L );
	
	//u32 options = state.GetValue ( 1, DEFAULT_OPTIONS );
	//UNTZ::System::get ()->_setOptions ( options );
	
	return 0;
}

//----------------------------------------------------------------//
// TODO: doxygen
int MOAIUntzSystem::_setOutputDevice ( lua_State* L ) {
	USLuaState state ( L );
	
	//u32 deviceIndex = state.GetValue ( 1, 0 );
	//UNTZ::System::get ()->setOutputDevice ( deviceIndex );
	
	return 0;
}

//----------------------------------------------------------------//
// TODO: doxygen
int MOAIUntzSystem::_setSampleRate ( lua_State* L ) {
	USLuaState state ( L );
	
	u32 sampleRate = state.GetValue ( 1, DEFAULT_SAMPLE_RATE );
	UNTZ::System::get ()->setSampleRate ( sampleRate );
	
	return 0;
}

//================================================================//
// MOAIUntzSystem
//================================================================//

//----------------------------------------------------------------//
MOAIUntzSystem::MOAIUntzSystem () {

	RTTI_SINGLE ( USLuaObject )
}

//----------------------------------------------------------------//
MOAIUntzSystem::~MOAIUntzSystem () {
}

//----------------------------------------------------------------//
void MOAIUntzSystem::RegisterLuaClass ( USLuaState& state ) {
	
	luaL_Reg regTable [] = {
		{ "getDeviceCount",			_getDeviceCount },
		{ "getDeviceInfo",			_getDeviceInfo },
		{ "getOptions",				_getOptions },
		{ "getSampleRate",			_getSampleRate },
		{ "getSupportedFormats",	_getSupportedFormats },
		{ "initialize",				_initialize },
		{ "setInputDevice",			_setInputDevice },
		{ "setOptions",				_setOptions },
		{ "setOutputDevice",		_setOutputDevice },
		{ "setSampleRate",			_setSampleRate },
		{ NULL, NULL }
	};

	luaL_register ( state, 0, regTable );
}

//----------------------------------------------------------------//
void MOAIUntzSystem::RegisterLuaFuncs ( USLuaState& state ) {
	UNUSED ( state );
}

//----------------------------------------------------------------//
STLString MOAIUntzSystem::ToString () {

	STLString repr;
	return repr;
}