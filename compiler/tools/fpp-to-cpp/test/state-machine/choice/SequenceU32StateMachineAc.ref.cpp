// ======================================================================
// \title  SequenceU32StateMachineAc.cpp
// \author Generated by fpp-to-cpp
// \brief  cpp file for SequenceU32 state machine
// ======================================================================

#include "Fw/Types/Assert.hpp"
#include "state-machine/choice/SequenceU32StateMachineAc.hpp"

namespace FppTest {

  namespace SmChoice {

    // ----------------------------------------------------------------------
    // Constructors and Destructors
    // ----------------------------------------------------------------------

    SequenceU32StateMachineBase ::
      SequenceU32StateMachineBase()
    {

    }

    SequenceU32StateMachineBase ::
      ~SequenceU32StateMachineBase()
    {

    }

    // ----------------------------------------------------------------------
    // Initialization
    // ----------------------------------------------------------------------

    void SequenceU32StateMachineBase ::
      initBase(const FwEnumStoreType id)
    {
      this->m_id = id;
      // Enter the initial target of the state machine
      this->enter_S1(Signal::__FPRIME_AC_INITIAL_TRANSITION);
    }

    // ----------------------------------------------------------------------
    // Getter functions
    // ----------------------------------------------------------------------

    SequenceU32StateMachineBase::State SequenceU32StateMachineBase ::
      getState() const
    {
      return this->m_state;
    }

    // ----------------------------------------------------------------------
    // Send signal functions
    // ----------------------------------------------------------------------

    void SequenceU32StateMachineBase ::
      sendSignal_s(U32 value)
    {
      switch (this->m_state) {
        case State::S1:
          // Enter the target
          this->enter_C1(Signal::s, value);
          break;
        case State::S2:
          break;
        case State::S3:
          break;
        case State::S4:
          break;
        default:
          FW_ASSERT(0, static_cast<FwAssertArgType>(this->m_state));
          break;
      }
    }

    // ----------------------------------------------------------------------
    // State and choice entry
    // ----------------------------------------------------------------------

    void SequenceU32StateMachineBase ::
      enter_S4(Signal signal)
    {
      this->m_state = State::S4;
    }

    void SequenceU32StateMachineBase ::
      enter_S3(Signal signal)
    {
      this->m_state = State::S3;
    }

    void SequenceU32StateMachineBase ::
      enter_S2(Signal signal)
    {
      this->m_state = State::S2;
    }

    void SequenceU32StateMachineBase ::
      enter_C2(
          Signal signal,
          U32 value
      )
    {
      if (this->guard_g2(signal, value)) {
        // Do the actions for the transition
        this->action_a(signal, value);
        // Enter the target
        this->enter_S3(signal);
      }
      else {
        // Do the actions for the transition
        this->action_b(signal);
        // Enter the target
        this->enter_S4(signal);
      }
    }

    void SequenceU32StateMachineBase ::
      enter_C1(
          Signal signal,
          U32 value
      )
    {
      if (this->guard_g1(signal)) {
        // Enter the target
        this->enter_S2(signal);
      }
      else {
        // Enter the target
        this->enter_C2(signal, value);
      }
    }

    void SequenceU32StateMachineBase ::
      enter_S1(Signal signal)
    {
      this->m_state = State::S1;
    }

  }

}
