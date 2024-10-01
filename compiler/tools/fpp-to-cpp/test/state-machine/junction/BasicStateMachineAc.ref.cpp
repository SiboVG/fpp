// ======================================================================
// \title  BasicStateMachineAc.cpp
// \author Generated by fpp-to-cpp
// \brief  cpp file for Basic state machine
// ======================================================================

#include "Fw/Types/Assert.hpp"
#include "junction/BasicStateMachineAc.hpp"

namespace FppTest {

  namespace SmJunction {

    // ----------------------------------------------------------------------
    // Constructors and Destructors
    // ----------------------------------------------------------------------

    BasicStateMachineBase ::
      BasicStateMachineBase()
    {

    }

    BasicStateMachineBase ::
      ~BasicStateMachineBase()
    {

    }

    // ----------------------------------------------------------------------
    // Initialization
    // ----------------------------------------------------------------------

    void BasicStateMachineBase ::
      init(const FwEnumStoreType id)
    {
      this->m_id = id;
      this->enter_S1(Signal::__FPRIME_AC_INITIAL_TRANSITION);
    }

    // ----------------------------------------------------------------------
    // Send signal functions
    // ----------------------------------------------------------------------

    void BasicStateMachineBase ::
      sendSignal_s()
    {
      switch (this->m_state) {
        case State::S1:
          this->enter_J(Signal::s);
          break;
        case State::S2:
          break;
        case State::S3:
          break;
        default:
          FW_ASSERT(0, static_cast<FwAssertArgType>(this->m_state));
          break;
      }
    }

    // ----------------------------------------------------------------------
    // State and junction entry
    // ----------------------------------------------------------------------

    void BasicStateMachineBase ::
      enter_S3(Signal signal)
    {
      this->m_state = State::S3;
    }

    void BasicStateMachineBase ::
      enter_S2(Signal signal)
    {
      this->m_state = State::S2;
    }

    void BasicStateMachineBase ::
      enter_J(Signal signal)
    {
      if (this->guard_g(signal)) {
        this->action_a(signal);
        this->enter_S2(signal);
      }
      else {
        this->action_b(signal);
        this->enter_S3(signal);
      }
    }

    void BasicStateMachineBase ::
      enter_S1(Signal signal)
    {
      this->m_state = State::S1;
    }

  }

}
