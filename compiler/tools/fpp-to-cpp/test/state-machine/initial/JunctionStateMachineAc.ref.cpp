// ======================================================================
// \title  JunctionStateMachineAc.cpp
// \author Generated by fpp-to-cpp
// \brief  cpp file for Junction state machine
// ======================================================================

#include "Fw/Types/Assert.hpp"
#include "JunctionStateMachineAc.hpp"

namespace FppTest {

  // ----------------------------------------------------------------------
  // Constructors and Destructors
  // ----------------------------------------------------------------------

  JunctionStateMachineBase ::
    JunctionStateMachineBase()
  {

  }

  JunctionStateMachineBase ::
    ~JunctionStateMachineBase()
  {

  }

  // ----------------------------------------------------------------------
  // Initialization
  // ----------------------------------------------------------------------

  void JunctionStateMachineBase ::
    init(const FwEnumStoreType id)
  {
    this->m_id = id;
    this->action_a(Signal::__FPRIME_AC_INITIAL_TRANSITION);
    this->enter_J(Signal::__FPRIME_AC_INITIAL_TRANSITION);
  }

  // ----------------------------------------------------------------------
  // State and junction entry
  // ----------------------------------------------------------------------

  void JunctionStateMachineBase ::
    enter_T(Signal signal)
  {
    this->action_a(signal);
    this->action_a(signal);
    this->m_state = State::T;
  }

  void JunctionStateMachineBase ::
    enter_S(Signal signal)
  {
    this->action_a(signal);
    this->m_state = State::S;
  }

  void JunctionStateMachineBase ::
    enter_J(Signal signal)
  {
    if (this->guard_g(signal)) {
      this->action_a(signal);
      this->enter_S(signal);
    }
    else {
      this->action_a(signal);
      this->action_a(signal);
      this->enter_T(signal);
    }
  }

}
