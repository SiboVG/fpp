// ======================================================================
// \title  BasicGuardTestStructStateMachineAc.cpp
// \author Generated by fpp-to-cpp
// \brief  cpp file for BasicGuardTestStruct state machine
// ======================================================================

#include "Fw/Types/Assert.hpp"
#include "state/BasicGuardTestStructStateMachineAc.hpp"

namespace FppTest {

  namespace SmState {

    // ----------------------------------------------------------------------
    // Constructors and Destructors
    // ----------------------------------------------------------------------

    BasicGuardTestStructStateMachineBase ::
      BasicGuardTestStructStateMachineBase()
    {

    }

    BasicGuardTestStructStateMachineBase ::
      ~BasicGuardTestStructStateMachineBase()
    {

    }

    // ----------------------------------------------------------------------
    // Initialization
    // ----------------------------------------------------------------------

    void BasicGuardTestStructStateMachineBase ::
      init(const FwEnumStoreType id)
    {
      this->m_id = id;
      this->enter_S(Signal::__FPRIME_AC_INITIAL_TRANSITION);
    }

    // ----------------------------------------------------------------------
    // Send signal functions
    // ----------------------------------------------------------------------

    void BasicGuardTestStructStateMachineBase ::
      sendSignal_s(const FppTest::SmHarness::TestStruct& value)
    {
      switch (this->m_state) {
        case State::S:
          if (this->guard_g(Signal::s, value)) {
            this->action_a(Signal::s, value);
            this->enter_T(Signal::s);
          }
          break;
        case State::T:
          break;
        default:
          FW_ASSERT(0, static_cast<FwAssertArgType>(this->m_state));
          break;
      }
    }

    // ----------------------------------------------------------------------
    // State and junction entry
    // ----------------------------------------------------------------------

    void BasicGuardTestStructStateMachineBase ::
      enter_T(Signal signal)
    {
      this->m_state = State::T;
    }

    void BasicGuardTestStructStateMachineBase ::
      enter_S(Signal signal)
    {
      this->m_state = State::S;
    }

  }

}
