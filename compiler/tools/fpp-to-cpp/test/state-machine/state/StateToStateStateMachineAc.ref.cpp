// ======================================================================
// \title  StateToStateStateMachineAc.cpp
// \author Generated by fpp-to-cpp
// \brief  cpp file for StateToState state machine
// ======================================================================

#include "Fw/Types/Assert.hpp"
#include "state-machine/state/StateToStateStateMachineAc.hpp"

namespace FppTest {

  namespace SmState {

    // ----------------------------------------------------------------------
    // Constructors and Destructors
    // ----------------------------------------------------------------------

    StateToStateStateMachineBase ::
      StateToStateStateMachineBase()
    {

    }

    StateToStateStateMachineBase ::
      ~StateToStateStateMachineBase()
    {

    }

    // ----------------------------------------------------------------------
    // Initialization
    // ----------------------------------------------------------------------

    void StateToStateStateMachineBase ::
      initBase(const FwEnumStoreType id)
    {
      this->m_id = id;
      // Enter the initial target of the state machine
      this->enter_S1(Signal::__FPRIME_AC_INITIAL_TRANSITION);
    }

    // ----------------------------------------------------------------------
    // Getter functions
    // ----------------------------------------------------------------------

    StateToStateStateMachineBase::State StateToStateStateMachineBase ::
      getState() const
    {
      return this->m_state;
    }

    // ----------------------------------------------------------------------
    // Send signal functions
    // ----------------------------------------------------------------------

    void StateToStateStateMachineBase ::
      sendSignal_S1_to_S4()
    {
      switch (this->m_state) {
        case State::S1_S2:
          // Do the actions for the transition
          this->action_exitS2(Signal::S1_to_S4);
          this->action_exitS1(Signal::S1_to_S4);
          this->action_a(Signal::S1_to_S4);
          // Enter the target
          this->enter_S4(Signal::S1_to_S4);
          break;
        case State::S1_S3:
          // Do the actions for the transition
          this->action_exitS3(Signal::S1_to_S4);
          this->action_exitS1(Signal::S1_to_S4);
          this->action_a(Signal::S1_to_S4);
          // Enter the target
          this->enter_S4(Signal::S1_to_S4);
          break;
        case State::S4_S5:
          break;
        default:
          FW_ASSERT(0, static_cast<FwAssertArgType>(this->m_state));
          break;
      }
    }

    void StateToStateStateMachineBase ::
      sendSignal_S1_to_S5()
    {
      switch (this->m_state) {
        case State::S1_S2:
          // Do the actions for the transition
          this->action_exitS2(Signal::S1_to_S5);
          this->action_exitS1(Signal::S1_to_S5);
          this->action_a(Signal::S1_to_S5);
          this->action_enterS4(Signal::S1_to_S5);
          // Enter the target
          this->enter_S4_S5(Signal::S1_to_S5);
          break;
        case State::S1_S3:
          // Do the actions for the transition
          this->action_exitS3(Signal::S1_to_S5);
          this->action_exitS1(Signal::S1_to_S5);
          this->action_a(Signal::S1_to_S5);
          this->action_enterS4(Signal::S1_to_S5);
          // Enter the target
          this->enter_S4_S5(Signal::S1_to_S5);
          break;
        case State::S4_S5:
          break;
        default:
          FW_ASSERT(0, static_cast<FwAssertArgType>(this->m_state));
          break;
      }
    }

    void StateToStateStateMachineBase ::
      sendSignal_S2_to_S3()
    {
      switch (this->m_state) {
        case State::S1_S2:
          // Do the actions for the transition
          this->action_exitS2(Signal::S2_to_S3);
          // Enter the target
          this->enter_S1_S3(Signal::S2_to_S3);
          break;
        case State::S1_S3:
          break;
        case State::S4_S5:
          break;
        default:
          FW_ASSERT(0, static_cast<FwAssertArgType>(this->m_state));
          break;
      }
    }

    // ----------------------------------------------------------------------
    // State and choice entry
    // ----------------------------------------------------------------------

    void StateToStateStateMachineBase ::
      enter_S4(Signal signal)
    {
      // Do the entry actions
      this->action_enterS4(signal);
      // Enter the target of the initial transition
      this->enter_S4_S5(signal);
    }

    void StateToStateStateMachineBase ::
      enter_S4_S5(Signal signal)
    {
      // Do the entry actions
      this->action_enterS5(signal);
      this->m_state = State::S4_S5;
    }

    void StateToStateStateMachineBase ::
      enter_S1(Signal signal)
    {
      // Do the entry actions
      this->action_enterS1(signal);
      // Enter the target of the initial transition
      this->enter_S1_S2(signal);
    }

    void StateToStateStateMachineBase ::
      enter_S1_S2(Signal signal)
    {
      // Do the entry actions
      this->action_enterS2(signal);
      this->m_state = State::S1_S2;
    }

    void StateToStateStateMachineBase ::
      enter_S1_S3(Signal signal)
    {
      // Do the entry actions
      this->action_enterS3(signal);
      this->m_state = State::S1_S3;
    }

  }

}
