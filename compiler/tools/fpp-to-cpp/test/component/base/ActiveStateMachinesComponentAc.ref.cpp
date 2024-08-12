// ======================================================================
// \title  ActiveStateMachinesComponentAc.cpp
// \author Generated by fpp-to-cpp
// \brief  cpp file for ActiveStateMachines component base class
// ======================================================================

#include "Fw/Types/Assert.hpp"
#include "Fw/Types/ExternalString.hpp"
#if FW_ENABLE_TEXT_LOGGING
#include "Fw/Types/String.hpp"
#endif
#include "base/ActiveStateMachinesComponentAc.hpp"

namespace {
  enum MsgTypeEnum {
    ACTIVESTATEMACHINES_COMPONENT_EXIT = Fw::ActiveComponentBase::ACTIVE_COMPONENT_EXIT,
    STATEMACHINE_SENDSIGNALS,
  };

  // Get the max size by constructing a union of the async input, command, and
  // internal port serialization sizes
  union BuffUnion {
    // Size of statemachine sendSignals
    BYTE sendSignalsStatemachineSize[
      Fw::SMSignals::SERIALIZED_SIZE
    ];
  };

  // Define a message buffer class large enough to handle all the
  // asynchronous inputs to the component
  class ComponentIpcSerializableBuffer :
    public Fw::SerializeBufferBase
  {

    public:

      enum {
        // Max. message size = size of data + message id + port
        SERIALIZATION_SIZE =
          sizeof(BuffUnion) +
          sizeof(FwEnumStoreType) +
          sizeof(FwIndexType)
      };

      Fw::Serializable::SizeType getBuffCapacity() const {
        return sizeof(m_buff);
      }

      U8* getBuffAddr() {
        return m_buff;
      }

      const U8* getBuffAddr() const {
        return m_buff;
      }

    private:
      // Should be the max of all the input ports serialized sizes...
      U8 m_buff[SERIALIZATION_SIZE];

  };
}

// ----------------------------------------------------------------------
// Component initialization
// ----------------------------------------------------------------------

void ActiveStateMachinesComponentBase ::
  init(
      FwQueueSizeType queueDepth,
      FwEnumStoreType instance
  )
{
  // Initialize base class
  Fw::ActiveComponentBase::init(instance);

  m_stateMachine_sm1.init();
  m_stateMachine_sm2.init();
  m_stateMachine_sm3.init();
  m_stateMachine_sm4.init();
  m_stateMachine_sm5.init();
  m_stateMachine_sm6.init();

  Os::Queue::QueueStatus qStat = this->createQueue(
    queueDepth,
    ComponentIpcSerializableBuffer::SERIALIZATION_SIZE
  );
  FW_ASSERT(
    Os::Queue::QUEUE_OK == qStat,
    static_cast<FwAssertArgType>(qStat)
  );
}

// ----------------------------------------------------------------------
// Component construction and destruction
// ----------------------------------------------------------------------

ActiveStateMachinesComponentBase ::
  ActiveStateMachinesComponentBase(const char* compName) :
    Fw::ActiveComponentBase(compName),
    m_stateMachine_sm1(this),
    m_stateMachine_sm2(this),
    m_stateMachine_sm3(this),
    m_stateMachine_sm4(this),
    m_stateMachine_sm5(this),
    m_stateMachine_sm6(this)
{

}

ActiveStateMachinesComponentBase ::
  ~ActiveStateMachinesComponentBase()
{

}

// ----------------------------------------------------------------------
// State machine function to push signals to the input queue
// ----------------------------------------------------------------------

void ActiveStateMachinesComponentBase ::
  stateMachineInvoke(const Fw::SMSignals& ev)
{

  ComponentIpcSerializableBuffer msg;
  Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;

  // Serialize the message ID
  _status = msg.serialize(static_cast<FwEnumStoreType>(STATEMACHINE_SENDSIGNALS));
  FW_ASSERT (
    _status == Fw::FW_SERIALIZE_OK,
    static_cast<FwAssertArgType>(_status)
  );

  // Fake port number to make message dequeue work
  _status = msg.serialize(static_cast<FwIndexType>(0));
  FW_ASSERT (
    _status == Fw::FW_SERIALIZE_OK,
    static_cast<FwAssertArgType>(_status)
  );

  _status = msg.serialize(ev);
  FW_ASSERT(
    _status == Fw::FW_SERIALIZE_OK,
    static_cast<FwAssertArgType>(_status)
  );

  switch (ev.getsmId()) {

    case STATE_MACHINE_SM2: {
                
      // Send message
      Os::Queue::QueueBlocking _block = Os::Queue::QUEUE_NONBLOCKING;
      Os::Queue::QueueStatus qStatus = this->m_queue.send(msg, 2, _block);

      FW_ASSERT(
        qStatus == Os::Queue::QUEUE_OK,
        static_cast<FwAssertArgType>(qStatus)
      );
      break;
    }

    case STATE_MACHINE_SM3: {
                
      // Send message
      Os::Queue::QueueBlocking _block = Os::Queue::QUEUE_NONBLOCKING;
      Os::Queue::QueueStatus qStatus = this->m_queue.send(msg, 3, _block);

      if (qStatus == Os::Queue::QUEUE_FULL) {
        this->incNumMsgDropped();
        return;
      }

      FW_ASSERT(
        qStatus == Os::Queue::QUEUE_OK,
        static_cast<FwAssertArgType>(qStatus)
      );
      break;
    }

    case STATE_MACHINE_SM6: {
                
      // Send message
      Os::Queue::QueueBlocking _block = Os::Queue::QUEUE_NONBLOCKING;
      Os::Queue::QueueStatus qStatus = this->m_queue.send(msg, 0, _block);

      FW_ASSERT(
        qStatus == Os::Queue::QUEUE_OK,
        static_cast<FwAssertArgType>(qStatus)
      );
      break;
    }

    case STATE_MACHINE_SM5: {
                
      // Send message
      Os::Queue::QueueBlocking _block = Os::Queue::QUEUE_BLOCKING;
      Os::Queue::QueueStatus qStatus = this->m_queue.send(msg, 0, _block);

      FW_ASSERT(
        qStatus == Os::Queue::QUEUE_OK,
        static_cast<FwAssertArgType>(qStatus)
      );
      break;
    }

    case STATE_MACHINE_SM1: {
                
      // Send message
      Os::Queue::QueueBlocking _block = Os::Queue::QUEUE_BLOCKING;
      Os::Queue::QueueStatus qStatus = this->m_queue.send(msg, 1, _block);

      FW_ASSERT(
        qStatus == Os::Queue::QUEUE_OK,
        static_cast<FwAssertArgType>(qStatus)
      );
      break;
    }

    case STATE_MACHINE_SM4: {
                
      // Send message
      Os::Queue::QueueBlocking _block = Os::Queue::QUEUE_NONBLOCKING;
      Os::Queue::QueueStatus qStatus = this->m_queue.send(msg, 4, _block);

      FW_ASSERT(
        qStatus == Os::Queue::QUEUE_OK,
        static_cast<FwAssertArgType>(qStatus)
      );
      break;
    }
  }
}

// ----------------------------------------------------------------------
// Message dispatch functions
// ----------------------------------------------------------------------

Fw::QueuedComponentBase::MsgDispatchStatus ActiveStateMachinesComponentBase ::
  doDispatch()
{
  ComponentIpcSerializableBuffer msg;
  FwQueuePriorityType priority = 0;

  Os::Queue::QueueStatus msgStatus = this->m_queue.receive(
    msg,
    priority,
    Os::Queue::QUEUE_BLOCKING
  );
  FW_ASSERT(
    msgStatus == Os::Queue::QUEUE_OK,
    static_cast<FwAssertArgType>(msgStatus)
  );

  // Reset to beginning of buffer
  msg.resetDeser();

  FwEnumStoreType desMsg = 0;
  Fw::SerializeStatus deserStatus = msg.deserialize(desMsg);
  FW_ASSERT(
    deserStatus == Fw::FW_SERIALIZE_OK,
    static_cast<FwAssertArgType>(deserStatus)
  );

  MsgTypeEnum msgType = static_cast<MsgTypeEnum>(desMsg);

  if (msgType == ACTIVESTATEMACHINES_COMPONENT_EXIT) {
    return MSG_DISPATCH_EXIT;
  }

  FwIndexType portNum = 0;
  deserStatus = msg.deserialize(portNum);
  FW_ASSERT(
    deserStatus == Fw::FW_SERIALIZE_OK,
    static_cast<FwAssertArgType>(deserStatus)
  );

  switch (msgType) {

    // Handle state machine signals 
    case STATEMACHINE_SENDSIGNALS: {
      Fw::SMSignals ev;
      deserStatus = msg.deserialize(ev);

      FW_ASSERT(
        Fw::FW_SERIALIZE_OK == deserStatus,
        static_cast<FwAssertArgType>(deserStatus)
      );

      // Make sure there was no data left over.
      // That means the buffer size was incorrect.
      FW_ASSERT(
        msg.getBuffLeft() == 0,
        static_cast<FwAssertArgType>(msg.getBuffLeft())
      );

      // Update the state machine with the signal
      switch (ev.getsmId()) {
        case STATE_MACHINE_SM1:
          this->m_stateMachine_sm1.update(&ev);
          break;
                  
        case STATE_MACHINE_SM2:
          this->m_stateMachine_sm2.update(&ev);
          break;
                  
        case STATE_MACHINE_SM3:
          this->m_stateMachine_sm3.update(&ev);
          break;
                  
        case STATE_MACHINE_SM4:
          this->m_stateMachine_sm4.update(&ev);
          break;
                  
        case STATE_MACHINE_SM5:
          this->m_stateMachine_sm5.update(&ev);
          break;
                  
        case STATE_MACHINE_SM6:
          this->m_stateMachine_sm6.update(&ev);
          break;
                  
      }

      break;
    }

    default:
      return MSG_DISPATCH_ERROR;
  }

  return MSG_DISPATCH_OK;
}
