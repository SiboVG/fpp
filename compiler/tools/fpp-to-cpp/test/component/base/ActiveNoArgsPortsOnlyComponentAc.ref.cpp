// ======================================================================
// \title  ActiveNoArgsPortsOnlyComponentAc.cpp
// \author Generated by fpp-to-cpp
// \brief  cpp file for ActiveNoArgsPortsOnly component base class
// ======================================================================

#include "Fw/Types/Assert.hpp"
#include "Fw/Types/ExternalString.hpp"
#if FW_ENABLE_TEXT_LOGGING
#include "Fw/Types/String.hpp"
#endif
#include "base/ActiveNoArgsPortsOnlyComponentAc.hpp"

namespace {
  enum MsgTypeEnum {
    ACTIVENOARGSPORTSONLY_COMPONENT_EXIT = Fw::ActiveComponentBase::ACTIVE_COMPONENT_EXIT,
    NOARGSASYNC_NOARGS,
  };

  // Define a message buffer class large enough to handle all the
  // asynchronous inputs to the component
  class ComponentIpcSerializableBuffer :
    public Fw::SerializeBufferBase
  {

    public:

      enum {
        // Offset into data in buffer: Size of message ID and port number
        DATA_OFFSET = sizeof(FwEnumStoreType) + sizeof(FwIndexType),
        // Max data size
        MAX_DATA_SIZE = 0,
        // Max message size: Size of message id + size of port + max data size
        SERIALIZATION_SIZE = DATA_OFFSET + MAX_DATA_SIZE
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

void ActiveNoArgsPortsOnlyComponentBase ::
  init(
      FwSizeType queueDepth,
      FwEnumStoreType instance
  )
{
  // Initialize base class
  Fw::ActiveComponentBase::init(instance);

  // Connect input port noArgsAsync
  for (
    FwIndexType port = 0;
    port < static_cast<FwIndexType>(this->getNum_noArgsAsync_InputPorts());
    port++
  ) {
    this->m_noArgsAsync_InputPort[port].init();
    this->m_noArgsAsync_InputPort[port].addCallComp(
      this,
      m_p_noArgsAsync_in
    );
    this->m_noArgsAsync_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
    Fw::ObjectName portName;
    portName.format(
      "%s_noArgsAsync_InputPort[%" PRI_PlatformIntType "]",
      this->m_objName.toChar(),
      port
    );
    this->m_noArgsAsync_InputPort[port].setObjName(portName.toChar());
#endif
  }

  // Connect input port noArgsGuarded
  for (
    FwIndexType port = 0;
    port < static_cast<FwIndexType>(this->getNum_noArgsGuarded_InputPorts());
    port++
  ) {
    this->m_noArgsGuarded_InputPort[port].init();
    this->m_noArgsGuarded_InputPort[port].addCallComp(
      this,
      m_p_noArgsGuarded_in
    );
    this->m_noArgsGuarded_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
    Fw::ObjectName portName;
    portName.format(
      "%s_noArgsGuarded_InputPort[%" PRI_PlatformIntType "]",
      this->m_objName.toChar(),
      port
    );
    this->m_noArgsGuarded_InputPort[port].setObjName(portName.toChar());
#endif
  }

  // Connect input port noArgsReturnGuarded
  for (
    FwIndexType port = 0;
    port < static_cast<FwIndexType>(this->getNum_noArgsReturnGuarded_InputPorts());
    port++
  ) {
    this->m_noArgsReturnGuarded_InputPort[port].init();
    this->m_noArgsReturnGuarded_InputPort[port].addCallComp(
      this,
      m_p_noArgsReturnGuarded_in
    );
    this->m_noArgsReturnGuarded_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
    Fw::ObjectName portName;
    portName.format(
      "%s_noArgsReturnGuarded_InputPort[%" PRI_PlatformIntType "]",
      this->m_objName.toChar(),
      port
    );
    this->m_noArgsReturnGuarded_InputPort[port].setObjName(portName.toChar());
#endif
  }

  // Connect input port noArgsReturnSync
  for (
    FwIndexType port = 0;
    port < static_cast<FwIndexType>(this->getNum_noArgsReturnSync_InputPorts());
    port++
  ) {
    this->m_noArgsReturnSync_InputPort[port].init();
    this->m_noArgsReturnSync_InputPort[port].addCallComp(
      this,
      m_p_noArgsReturnSync_in
    );
    this->m_noArgsReturnSync_InputPort[port].setPortNum(port);

#if FW_OBJECT_NAMES == 1
    Fw::ObjectName portName;
    portName.format(
      "%s_noArgsReturnSync_InputPort[%" PRI_PlatformIntType "]",
      this->m_objName.toChar(),
      port
    );
    this->m_noArgsReturnSync_InputPort[port].setObjName(portName.toChar());
#endif
  }

  // Connect output port noArgsOut
  for (
    FwIndexType port = 0;
    port < static_cast<FwIndexType>(this->getNum_noArgsOut_OutputPorts());
    port++
  ) {
    this->m_noArgsOut_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
    Fw::ObjectName portName;
    portName.format(
      "%s_noArgsOut_OutputPort[%" PRI_PlatformIntType "]",
      this->m_objName.toChar(),
      port
    );
    this->m_noArgsOut_OutputPort[port].setObjName(portName.toChar());
#endif
  }

  // Connect output port noArgsReturnOut
  for (
    FwIndexType port = 0;
    port < static_cast<FwIndexType>(this->getNum_noArgsReturnOut_OutputPorts());
    port++
  ) {
    this->m_noArgsReturnOut_OutputPort[port].init();

#if FW_OBJECT_NAMES == 1
    Fw::ObjectName portName;
    portName.format(
      "%s_noArgsReturnOut_OutputPort[%" PRI_PlatformIntType "]",
      this->m_objName.toChar(),
      port
    );
    this->m_noArgsReturnOut_OutputPort[port].setObjName(portName.toChar());
#endif
  }

  // Create the queue
  Os::Queue::Status qStat = this->createQueue(
    queueDepth,
    static_cast<FwSizeType>(ComponentIpcSerializableBuffer::SERIALIZATION_SIZE)
  );
  FW_ASSERT(
    Os::Queue::Status::OP_OK == qStat,
    static_cast<FwAssertArgType>(qStat)
  );
}

// ----------------------------------------------------------------------
// Getters for typed input ports
// ----------------------------------------------------------------------

Ports::InputNoArgsPort* ActiveNoArgsPortsOnlyComponentBase ::
  get_noArgsAsync_InputPort(FwIndexType portNum)
{
  FW_ASSERT(
    portNum < this->getNum_noArgsAsync_InputPorts(),
    static_cast<FwAssertArgType>(portNum)
  );

  return &this->m_noArgsAsync_InputPort[portNum];
}

Ports::InputNoArgsPort* ActiveNoArgsPortsOnlyComponentBase ::
  get_noArgsGuarded_InputPort(FwIndexType portNum)
{
  FW_ASSERT(
    portNum < this->getNum_noArgsGuarded_InputPorts(),
    static_cast<FwAssertArgType>(portNum)
  );

  return &this->m_noArgsGuarded_InputPort[portNum];
}

Ports::InputNoArgsReturnPort* ActiveNoArgsPortsOnlyComponentBase ::
  get_noArgsReturnGuarded_InputPort(FwIndexType portNum)
{
  FW_ASSERT(
    portNum < this->getNum_noArgsReturnGuarded_InputPorts(),
    static_cast<FwAssertArgType>(portNum)
  );

  return &this->m_noArgsReturnGuarded_InputPort[portNum];
}

Ports::InputNoArgsReturnPort* ActiveNoArgsPortsOnlyComponentBase ::
  get_noArgsReturnSync_InputPort(FwIndexType portNum)
{
  FW_ASSERT(
    portNum < this->getNum_noArgsReturnSync_InputPorts(),
    static_cast<FwAssertArgType>(portNum)
  );

  return &this->m_noArgsReturnSync_InputPort[portNum];
}

// ----------------------------------------------------------------------
// Connect typed input ports to typed output ports
// ----------------------------------------------------------------------

void ActiveNoArgsPortsOnlyComponentBase ::
  set_noArgsOut_OutputPort(
      FwIndexType portNum,
      Ports::InputNoArgsPort* port
  )
{
  FW_ASSERT(
    portNum < this->getNum_noArgsOut_OutputPorts(),
    static_cast<FwAssertArgType>(portNum)
  );

  this->m_noArgsOut_OutputPort[portNum].addCallPort(port);
}

void ActiveNoArgsPortsOnlyComponentBase ::
  set_noArgsReturnOut_OutputPort(
      FwIndexType portNum,
      Ports::InputNoArgsReturnPort* port
  )
{
  FW_ASSERT(
    portNum < this->getNum_noArgsReturnOut_OutputPorts(),
    static_cast<FwAssertArgType>(portNum)
  );

  this->m_noArgsReturnOut_OutputPort[portNum].addCallPort(port);
}

#if FW_PORT_SERIALIZATION

// ----------------------------------------------------------------------
// Connect serial input ports to typed output ports
// ----------------------------------------------------------------------

void ActiveNoArgsPortsOnlyComponentBase ::
  set_noArgsOut_OutputPort(
      FwIndexType portNum,
      Fw::InputSerializePort* port
  )
{
  FW_ASSERT(
    portNum < this->getNum_noArgsOut_OutputPorts(),
    static_cast<FwAssertArgType>(portNum)
  );

  this->m_noArgsOut_OutputPort[portNum].registerSerialPort(port);
}

#endif

// ----------------------------------------------------------------------
// Component construction and destruction
// ----------------------------------------------------------------------

ActiveNoArgsPortsOnlyComponentBase ::
  ActiveNoArgsPortsOnlyComponentBase(const char* compName) :
    Fw::ActiveComponentBase(compName)
{

}

ActiveNoArgsPortsOnlyComponentBase ::
  ~ActiveNoArgsPortsOnlyComponentBase()
{

}

// ----------------------------------------------------------------------
// Getters for numbers of typed input ports
// ----------------------------------------------------------------------

FwIndexType ActiveNoArgsPortsOnlyComponentBase ::
  getNum_noArgsAsync_InputPorts() const
{
  return static_cast<FwIndexType>(FW_NUM_ARRAY_ELEMENTS(this->m_noArgsAsync_InputPort));
}

FwIndexType ActiveNoArgsPortsOnlyComponentBase ::
  getNum_noArgsGuarded_InputPorts() const
{
  return static_cast<FwIndexType>(FW_NUM_ARRAY_ELEMENTS(this->m_noArgsGuarded_InputPort));
}

FwIndexType ActiveNoArgsPortsOnlyComponentBase ::
  getNum_noArgsReturnGuarded_InputPorts() const
{
  return static_cast<FwIndexType>(FW_NUM_ARRAY_ELEMENTS(this->m_noArgsReturnGuarded_InputPort));
}

FwIndexType ActiveNoArgsPortsOnlyComponentBase ::
  getNum_noArgsReturnSync_InputPorts() const
{
  return static_cast<FwIndexType>(FW_NUM_ARRAY_ELEMENTS(this->m_noArgsReturnSync_InputPort));
}

// ----------------------------------------------------------------------
// Getters for numbers of typed output ports
// ----------------------------------------------------------------------

FwIndexType ActiveNoArgsPortsOnlyComponentBase ::
  getNum_noArgsOut_OutputPorts() const
{
  return static_cast<FwIndexType>(FW_NUM_ARRAY_ELEMENTS(this->m_noArgsOut_OutputPort));
}

FwIndexType ActiveNoArgsPortsOnlyComponentBase ::
  getNum_noArgsReturnOut_OutputPorts() const
{
  return static_cast<FwIndexType>(FW_NUM_ARRAY_ELEMENTS(this->m_noArgsReturnOut_OutputPort));
}

// ----------------------------------------------------------------------
// Connection status queries for typed output ports
// ----------------------------------------------------------------------

bool ActiveNoArgsPortsOnlyComponentBase ::
  isConnected_noArgsOut_OutputPort(FwIndexType portNum)
{
  FW_ASSERT(
    portNum < this->getNum_noArgsOut_OutputPorts(),
    static_cast<FwAssertArgType>(portNum)
  );

  return this->m_noArgsOut_OutputPort[portNum].isConnected();
}

bool ActiveNoArgsPortsOnlyComponentBase ::
  isConnected_noArgsReturnOut_OutputPort(FwIndexType portNum)
{
  FW_ASSERT(
    portNum < this->getNum_noArgsReturnOut_OutputPorts(),
    static_cast<FwAssertArgType>(portNum)
  );

  return this->m_noArgsReturnOut_OutputPort[portNum].isConnected();
}

// ----------------------------------------------------------------------
// Port handler base-class functions for typed input ports
//
// Call these functions directly to bypass the corresponding ports
// ----------------------------------------------------------------------

void ActiveNoArgsPortsOnlyComponentBase ::
  noArgsAsync_handlerBase(FwIndexType portNum)
{
  // Make sure port number is valid
  FW_ASSERT(
    portNum < this->getNum_noArgsAsync_InputPorts(),
    static_cast<FwAssertArgType>(portNum)
  );

  // Call pre-message hook
  noArgsAsync_preMsgHook(portNum);
  ComponentIpcSerializableBuffer msg;
  Fw::SerializeStatus _status = Fw::FW_SERIALIZE_OK;

  // Serialize message ID
  _status = msg.serialize(
    static_cast<FwEnumStoreType>(NOARGSASYNC_NOARGS)
  );
  FW_ASSERT(
    _status == Fw::FW_SERIALIZE_OK,
    static_cast<FwAssertArgType>(_status)
  );

  // Serialize port number
  _status = msg.serialize(portNum);
  FW_ASSERT(
    _status == Fw::FW_SERIALIZE_OK,
    static_cast<FwAssertArgType>(_status)
  );

  // Send message
  Os::Queue::BlockingType _block = Os::Queue::NONBLOCKING;
  Os::Queue::Status qStatus = this->m_queue.send(msg, 0, _block);

  FW_ASSERT(
    qStatus == Os::Queue::OP_OK,
    static_cast<FwAssertArgType>(qStatus)
  );
}

void ActiveNoArgsPortsOnlyComponentBase ::
  noArgsGuarded_handlerBase(FwIndexType portNum)
{
  // Make sure port number is valid
  FW_ASSERT(
    portNum < this->getNum_noArgsGuarded_InputPorts(),
    static_cast<FwAssertArgType>(portNum)
  );

  // Lock guard mutex before calling
  this->lock();

  // Call handler function
  this->noArgsGuarded_handler(portNum);

  // Unlock guard mutex
  this->unLock();
}

U32 ActiveNoArgsPortsOnlyComponentBase ::
  noArgsReturnGuarded_handlerBase(FwIndexType portNum)
{
  // Make sure port number is valid
  FW_ASSERT(
    portNum < this->getNum_noArgsReturnGuarded_InputPorts(),
    static_cast<FwAssertArgType>(portNum)
  );

  U32 retVal;

  // Lock guard mutex before calling
  this->lock();

  // Call handler function
  retVal = this->noArgsReturnGuarded_handler(portNum);

  // Unlock guard mutex
  this->unLock();

  return retVal;
}

U32 ActiveNoArgsPortsOnlyComponentBase ::
  noArgsReturnSync_handlerBase(FwIndexType portNum)
{
  // Make sure port number is valid
  FW_ASSERT(
    portNum < this->getNum_noArgsReturnSync_InputPorts(),
    static_cast<FwAssertArgType>(portNum)
  );

  U32 retVal;

  // Call handler function
  retVal = this->noArgsReturnSync_handler(portNum);

  return retVal;
}

// ----------------------------------------------------------------------
// Pre-message hooks for typed async input ports
//
// Each of these functions is invoked just before processing a message
// on the corresponding port. By default, they do nothing. You can
// override them to provide specific pre-message behavior.
// ----------------------------------------------------------------------

void ActiveNoArgsPortsOnlyComponentBase ::
  noArgsAsync_preMsgHook(FwIndexType portNum)
{
  // Default: no-op
}

// ----------------------------------------------------------------------
// Invocation functions for typed output ports
// ----------------------------------------------------------------------

void ActiveNoArgsPortsOnlyComponentBase ::
  noArgsOut_out(FwIndexType portNum)
{
  FW_ASSERT(
    portNum < this->getNum_noArgsOut_OutputPorts(),
    static_cast<FwAssertArgType>(portNum)
  );
  this->m_noArgsOut_OutputPort[portNum].invoke();
}

U32 ActiveNoArgsPortsOnlyComponentBase ::
  noArgsReturnOut_out(FwIndexType portNum)
{
  FW_ASSERT(
    portNum < this->getNum_noArgsReturnOut_OutputPorts(),
    static_cast<FwAssertArgType>(portNum)
  );
  return this->m_noArgsReturnOut_OutputPort[portNum].invoke();
}

// ----------------------------------------------------------------------
// Mutex operations for guarded ports
//
// You can override these operations to provide more sophisticated
// synchronization
// ----------------------------------------------------------------------

void ActiveNoArgsPortsOnlyComponentBase ::
  lock()
{
  this->m_guardedPortMutex.lock();
}

void ActiveNoArgsPortsOnlyComponentBase ::
  unLock()
{
  this->m_guardedPortMutex.unLock();
}

// ----------------------------------------------------------------------
// Message dispatch functions
// ----------------------------------------------------------------------

Fw::QueuedComponentBase::MsgDispatchStatus ActiveNoArgsPortsOnlyComponentBase ::
  doDispatch()
{
  ComponentIpcSerializableBuffer msg;
  FwQueuePriorityType priority = 0;

  Os::Queue::Status msgStatus = this->m_queue.receive(
    msg,
    Os::Queue::BLOCKING,
    priority
  );
  FW_ASSERT(
    msgStatus == Os::Queue::OP_OK,
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

  if (msgType == ACTIVENOARGSPORTSONLY_COMPONENT_EXIT) {
    return MSG_DISPATCH_EXIT;
  }

  FwIndexType portNum = 0;
  deserStatus = msg.deserialize(portNum);
  FW_ASSERT(
    deserStatus == Fw::FW_SERIALIZE_OK,
    static_cast<FwAssertArgType>(deserStatus)
  );

  switch (msgType) {
    // Handle async input port noArgsAsync
    case NOARGSASYNC_NOARGS: {
      // Call handler function
      this->noArgsAsync_handler(portNum);

      break;
    }

    default:
      return MSG_DISPATCH_ERROR;
  }

  return MSG_DISPATCH_OK;
}

// ----------------------------------------------------------------------
// Calls for messages received on typed input ports
// ----------------------------------------------------------------------

void ActiveNoArgsPortsOnlyComponentBase ::
  m_p_noArgsAsync_in(
      Fw::PassiveComponentBase* callComp,
      FwIndexType portNum
  )
{
  FW_ASSERT(callComp);
  ActiveNoArgsPortsOnlyComponentBase* compPtr = static_cast<ActiveNoArgsPortsOnlyComponentBase*>(callComp);
  compPtr->noArgsAsync_handlerBase(portNum);
}

void ActiveNoArgsPortsOnlyComponentBase ::
  m_p_noArgsGuarded_in(
      Fw::PassiveComponentBase* callComp,
      FwIndexType portNum
  )
{
  FW_ASSERT(callComp);
  ActiveNoArgsPortsOnlyComponentBase* compPtr = static_cast<ActiveNoArgsPortsOnlyComponentBase*>(callComp);
  compPtr->noArgsGuarded_handlerBase(portNum);
}

U32 ActiveNoArgsPortsOnlyComponentBase ::
  m_p_noArgsReturnGuarded_in(
      Fw::PassiveComponentBase* callComp,
      FwIndexType portNum
  )
{
  FW_ASSERT(callComp);
  ActiveNoArgsPortsOnlyComponentBase* compPtr = static_cast<ActiveNoArgsPortsOnlyComponentBase*>(callComp);
  return compPtr->noArgsReturnGuarded_handlerBase(portNum);
}

U32 ActiveNoArgsPortsOnlyComponentBase ::
  m_p_noArgsReturnSync_in(
      Fw::PassiveComponentBase* callComp,
      FwIndexType portNum
  )
{
  FW_ASSERT(callComp);
  ActiveNoArgsPortsOnlyComponentBase* compPtr = static_cast<ActiveNoArgsPortsOnlyComponentBase*>(callComp);
  return compPtr->noArgsReturnSync_handlerBase(portNum);
}
