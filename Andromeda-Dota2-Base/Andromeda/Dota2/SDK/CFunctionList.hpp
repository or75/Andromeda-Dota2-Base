#pragma once

#include <vector>
#include <Common/Common.hpp>

#include <Dota2/SDK/SDK.hpp>
#include <Dota2/CBasePattern.hpp>

#define DECLARATE_DOTA2_FUNCTION_SDK_FASTCALL(Ret,Function,Param,UsingParam,CallParam)\
inline Ret Function Param\
{\
	using Fn = Ret ( __fastcall* ) UsingParam;\
	Fn Original = static_cast<Fn>( GetFunctionList()->##Function##.GetFunction() );\
	return Original##CallParam##;\
}

class CFunctionList final
{
public:
	auto OnInit() -> bool;

public:
	CBasePattern CGameEntitySystem_GetLocalPlayerController = { "CGameEntitySystem::GetLocalPlayerController" , "E8 ? ? ? ? 48 89 44 24 ? 48 8B F8 48 85 C0 0F 84 ? ? ? ? 4C 89 AC 24 ? ? ? ? 48 8D 54 24 ?" , CLIENT_DLL , 0 , SEARCH_TYPE_CALL };
	CBasePattern GetCUserCmdTick = { "GetCUserCmdTick" , "48 83 EC ? 4C 8B 0D ? ? ? ? 4C 8B DA" , CLIENT_DLL , 0 , SEARCH_TYPE_NONE };
	CBasePattern GetCUserCmdArray = { "GetCUserCmdArray" , "48 89 4C 24 ? 41 56 41 57" , CLIENT_DLL , 0 , SEARCH_TYPE_NONE };
	CBasePattern GetCUserCmdBySequenceNumber = { "GetCUserCmdBySequenceNumber" , "40 53 48 83 EC ? 8B DA E8 ? ? ? ? 4C 8B C0" , CLIENT_DLL , 0 , SEARCH_TYPE_NONE };
};

auto GetFunctionList() -> CFunctionList*;
