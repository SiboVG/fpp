// ======================================================================
// \title  ActiveEvents.cpp
// \author [user name]
// \brief  cpp file for ActiveEvents component implementation class
// ======================================================================

#include "ActiveEvents.hpp"

// ----------------------------------------------------------------------
// Component construction and destruction
// ----------------------------------------------------------------------

ActiveEvents ::
  ActiveEvents(const char* const compName) :
    ActiveEventsComponentBase(compName)
{

}

ActiveEvents ::
  ~ActiveEvents()
{

}

// ----------------------------------------------------------------------
// Handler implementations for typed input ports
// ----------------------------------------------------------------------

void ActiveEvents ::
  aliasTypedAsync_handler(
      FwIndexType portNum,
      AliasPrim1 u32,
      AliasPrim2 f32,
      AliasBool b,
      const Fw::StringBase& str2,
      const AliasEnum& e,
      const AliasArray& a,
      const AliasStruct& s
  )
{
  // TODO
}

Fw::String ActiveEvents ::
  noArgsAliasStringReturnSync_handler(FwIndexType portNum)
{
  // TODO return
}

void ActiveEvents ::
  noArgsAsync_handler(FwIndexType portNum)
{
  // TODO
}

void ActiveEvents ::
  noArgsGuarded_handler(FwIndexType portNum)
{
  // TODO
}

U32 ActiveEvents ::
  noArgsReturnGuarded_handler(FwIndexType portNum)
{
  // TODO return
}

U32 ActiveEvents ::
  noArgsReturnSync_handler(FwIndexType portNum)
{
  // TODO return
}

Fw::String ActiveEvents ::
  noArgsStringReturnSync_handler(FwIndexType portNum)
{
  // TODO return
}

void ActiveEvents ::
  noArgsSync_handler(FwIndexType portNum)
{
  // TODO
}

void ActiveEvents ::
  typedAliasGuarded_handler(
      FwIndexType portNum,
      AliasPrim1 u32,
      AliasPrim2 f32,
      AliasBool b,
      const Fw::StringBase& str2,
      const AliasEnum& e,
      const AliasArray& a,
      const AliasStruct& s
  )
{
  // TODO
}

AliasPrim2 ActiveEvents ::
  typedAliasReturnSync_handler(
      FwIndexType portNum,
      AliasPrim1 u32,
      AliasPrim2 f32,
      AliasBool b,
      const Fw::StringBase& str2,
      const AliasEnum& e,
      const AliasArray& a,
      const AliasStruct& s
  )
{
  // TODO return
}

Fw::String ActiveEvents ::
  typedAliasStringReturnSync_handler(
      FwIndexType portNum,
      AliasPrim1 u32,
      AliasPrim2 f32,
      AliasBool b,
      const Fw::StringBase& str2,
      const AliasEnum& e,
      const AliasArray& a,
      const AnotherAliasStruct& s
  )
{
  // TODO return
}

void ActiveEvents ::
  typedAsync_handler(
      FwIndexType portNum,
      U32 u32,
      F32 f32,
      bool b,
      const Fw::StringBase& str1,
      const E& e,
      const A& a,
      const S& s
  )
{
  // TODO
}

void ActiveEvents ::
  typedAsyncAssert_handler(
      FwIndexType portNum,
      U32 u32,
      F32 f32,
      bool b,
      const Fw::StringBase& str1,
      const E& e,
      const A& a,
      const S& s
  )
{
  // TODO
}

void ActiveEvents ::
  typedAsyncBlockPriority_handler(
      FwIndexType portNum,
      U32 u32,
      F32 f32,
      bool b,
      const Fw::StringBase& str1,
      const E& e,
      const A& a,
      const S& s
  )
{
  // TODO
}

void ActiveEvents ::
  typedAsyncDropPriority_handler(
      FwIndexType portNum,
      U32 u32,
      F32 f32,
      bool b,
      const Fw::StringBase& str1,
      const E& e,
      const A& a,
      const S& s
  )
{
  // TODO
}

void ActiveEvents ::
  typedGuarded_handler(
      FwIndexType portNum,
      U32 u32,
      F32 f32,
      bool b,
      const Fw::StringBase& str1,
      const E& e,
      const A& a,
      const S& s
  )
{
  // TODO
}

F32 ActiveEvents ::
  typedReturnGuarded_handler(
      FwIndexType portNum,
      U32 u32,
      F32 f32,
      bool b,
      const Fw::StringBase& str2,
      const E& e,
      const A& a,
      const S& s
  )
{
  // TODO return
}

F32 ActiveEvents ::
  typedReturnSync_handler(
      FwIndexType portNum,
      U32 u32,
      F32 f32,
      bool b,
      const Fw::StringBase& str2,
      const E& e,
      const A& a,
      const S& s
  )
{
  // TODO return
}

void ActiveEvents ::
  typedSync_handler(
      FwIndexType portNum,
      U32 u32,
      F32 f32,
      bool b,
      const Fw::StringBase& str1,
      const E& e,
      const A& a,
      const S& s
  )
{
  // TODO
}
