// ======================================================================
// \title  NestedStateMachineAc.cpp
// \author Generated by fpp-to-cpp
// \brief  cpp file for Nested state machine
// ======================================================================

#include "Fw/Types/Assert.hpp"
#include "NestedStateMachineAc.hpp"

namespace FppTest {

  // ----------------------------------------------------------------------
  // Constructors and Destructors
  // ----------------------------------------------------------------------

  NestedStateMachineBase ::
    NestedStateMachineBase()
  {

  }

  NestedStateMachineBase ::
    ~NestedStateMachineBase()
  {

  }

  // ----------------------------------------------------------------------
  // Initialization
  // ----------------------------------------------------------------------

  void NestedStateMachineBase ::
    init(const FwEnumStoreType id)
  {
    this->m_id = id;
    this->action_a(Signal::__FPRIME_AC_INITIAL_TRANSITION);
    this->enter_S(Signal::__FPRIME_AC_INITIAL_TRANSITION);
  }

  // ----------------------------------------------------------------------
  // State and junction entry
  // ----------------------------------------------------------------------

  void NestedStateMachineBase ::
    enter_S(Signal signal)
  {
    this->action_a(signal);
    this->action_a(signal);
    this->enter_S_T(signal);
  }

  void NestedStateMachineBase ::
    enter_S_T(Signal signal)
  {
    this->action_a(signal);
    this->action_a(signal);
    this->action_a(signal);
    this->m_state = State::S_T;
  }

}
