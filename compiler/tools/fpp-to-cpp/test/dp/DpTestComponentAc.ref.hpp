// ======================================================================
// \title  DpTestComponentAc.hpp
// \author Generated by fpp-to-cpp
// \brief  hpp file for DpTest component base class
// ======================================================================

#ifndef FppTest_DpTestComponentAc_HPP
#define FppTest_DpTestComponentAc_HPP

#include "DpTest_DataSerializableAc.hpp"
#include "FpConfig.hpp"
#include "Fw/Comp/ActiveComponentBase.hpp"
#include "Fw/Dp/DpContainer.hpp"
#include "Fw/Dp/DpRequestPortAc.hpp"
#include "Fw/Dp/DpResponsePortAc.hpp"
#include "Fw/Dp/DpSendPortAc.hpp"
#include "Fw/Port/InputSerializePort.hpp"
#include "Fw/Port/OutputSerializePort.hpp"
#include "Fw/Time/TimePortAc.hpp"
#include "Fw/Types/ByteArray.hpp"
#include "Svc/Sched/SchedPortAc.hpp"

namespace FppTest {

  //! \class DpTestComponentBase
  //! \brief Auto-generated base for DpTest component
  //!
  //! A component for testing  data product code gen
  class DpTestComponentBase :
    public Fw::ActiveComponentBase
  {

      // ----------------------------------------------------------------------
      // Friend classes
      // ----------------------------------------------------------------------

      //! Friend class for white-box testing
      friend class DpTestComponentBaseFriend;

    PROTECTED:

      // ----------------------------------------------------------------------
      // Constants
      // ----------------------------------------------------------------------

      //! Enumerations for numbers of special input ports
      enum {
        NUM_PRODUCTRECVIN_INPUT_PORTS = 1,
      };

      //! Enumerations for numbers of typed input ports
      enum {
        NUM_SCHEDIN_INPUT_PORTS = 1,
      };

      //! Enumerations for numbers of special output ports
      enum {
        NUM_PRODUCTREQUESTOUT_OUTPUT_PORTS = 1,
        NUM_PRODUCTSENDOUT_OUTPUT_PORTS = 1,
        NUM_TIMEGETOUT_OUTPUT_PORTS = 1,
      };

    PROTECTED:

      // ----------------------------------------------------------------------
      // Types for data products
      // ----------------------------------------------------------------------

      //! The container ids
      struct ContainerId {
        enum T : FwDpIdType {
          Container1 = 300,
          Container2 = 400,
        };
      };

      //! The container default priorities
      struct ContainerPriority {
        enum T : FwDpPriorityType {
          Container1 = 10,
          Container2 = 20,
        };
      };

      //! The record ids
      struct RecordId {
        enum T : FwDpIdType {
          U32Record = 100,
          DataRecord = 200,
          RawRecord = 300,
        };
      };

      //! A data product container
      class DpContainer :
        public Fw::DpContainer
      {

        public:

          //! Constructor
          DpContainer(
              FwDpIdType id, //!< The container id
              const Fw::Buffer& buffer, //!< The packet buffer
              FwDpIdType baseId //!< The component base id
          );

        public:

          //! Serialize a DataRecord record into the packet buffer
          //! \return The serialize status
          Fw::SerializeStatus serializeRecord_DataRecord(
              const FppTest::DpTest_Data& elt //!< The element
          );

          //! Serialize a RawRecord record into the packet buffer
          //! \return The serialize status
          Fw::SerializeStatus serializeRecord_RawRecord(
              Fw::ByteArray byteArray //!< The raw byte array
          );

          //! Serialize a U32Record record into the packet buffer
          //! \return The serialize status
          Fw::SerializeStatus serializeRecord_U32Record(
              U32 elt //!< The element
          );

        PRIVATE:

          //! The component base id
          FwDpIdType baseId;

      };

    public:

      // ----------------------------------------------------------------------
      // Component initialization
      // ----------------------------------------------------------------------

      //! Initialize DpTestComponentBase object
      void init(
          NATIVE_INT_TYPE queueDepth, //!< The queue depth
          NATIVE_INT_TYPE instance = 0 //!< The instance number
      );

    public:

      // ----------------------------------------------------------------------
      // Getters for special input ports
      // ----------------------------------------------------------------------

      //! Get special input port at index
      //!
      //! \return productRecvIn[portNum]
      Fw::InputDpResponsePort* get_productRecvIn_InputPort(
          NATIVE_INT_TYPE portNum //!< The port number
      );

    public:

      // ----------------------------------------------------------------------
      // Getters for typed input ports
      // ----------------------------------------------------------------------

      //! Get typed input port at index
      //!
      //! \return schedIn[portNum]
      Svc::InputSchedPort* get_schedIn_InputPort(
          NATIVE_INT_TYPE portNum //!< The port number
      );

    public:

      // ----------------------------------------------------------------------
      // Connect input ports to special output ports
      // ----------------------------------------------------------------------

      //! Connect port to productRequestOut[portNum]
      void set_productRequestOut_OutputPort(
          NATIVE_INT_TYPE portNum, //!< The port number
          Fw::InputDpRequestPort* port //!< The input port
      );

      //! Connect port to productSendOut[portNum]
      void set_productSendOut_OutputPort(
          NATIVE_INT_TYPE portNum, //!< The port number
          Fw::InputDpSendPort* port //!< The input port
      );

      //! Connect port to timeGetOut[portNum]
      void set_timeGetOut_OutputPort(
          NATIVE_INT_TYPE portNum, //!< The port number
          Fw::InputTimePort* port //!< The input port
      );

#if FW_PORT_SERIALIZATION

    public:

      // ----------------------------------------------------------------------
      // Connect serial input ports to special output ports
      // ----------------------------------------------------------------------

      //! Connect port to productRequestOut[portNum]
      void set_productRequestOut_OutputPort(
          NATIVE_INT_TYPE portNum, //!< The port number
          Fw::InputSerializePort* port //!< The port
      );

      //! Connect port to productSendOut[portNum]
      void set_productSendOut_OutputPort(
          NATIVE_INT_TYPE portNum, //!< The port number
          Fw::InputSerializePort* port //!< The port
      );

      //! Connect port to timeGetOut[portNum]
      void set_timeGetOut_OutputPort(
          NATIVE_INT_TYPE portNum, //!< The port number
          Fw::InputSerializePort* port //!< The port
      );

#endif

    PROTECTED:

      // ----------------------------------------------------------------------
      // Component construction and destruction
      // ----------------------------------------------------------------------

      //! Construct DpTestComponentBase object
      DpTestComponentBase(
          const char* compName = "" //!< The component name
      );

      //! Destroy DpTestComponentBase object
      virtual ~DpTestComponentBase();

    PROTECTED:

      // ----------------------------------------------------------------------
      // Getters for numbers of special input ports
      // ----------------------------------------------------------------------

      //! Get the number of productRecvIn input ports
      //!
      //! \return The number of productRecvIn input ports
      NATIVE_INT_TYPE getNum_productRecvIn_InputPorts();

    PROTECTED:

      // ----------------------------------------------------------------------
      // Getters for numbers of typed input ports
      // ----------------------------------------------------------------------

      //! Get the number of schedIn input ports
      //!
      //! \return The number of schedIn input ports
      NATIVE_INT_TYPE getNum_schedIn_InputPorts();

    PROTECTED:

      // ----------------------------------------------------------------------
      // Getters for numbers of special output ports
      // ----------------------------------------------------------------------

      //! Get the number of productRequestOut output ports
      //!
      //! \return The number of productRequestOut output ports
      NATIVE_INT_TYPE getNum_productRequestOut_OutputPorts();

      //! Get the number of productSendOut output ports
      //!
      //! \return The number of productSendOut output ports
      NATIVE_INT_TYPE getNum_productSendOut_OutputPorts();

      //! Get the number of timeGetOut output ports
      //!
      //! \return The number of timeGetOut output ports
      NATIVE_INT_TYPE getNum_timeGetOut_OutputPorts();

    PROTECTED:

      // ----------------------------------------------------------------------
      // Connection status queries for special output ports
      // ----------------------------------------------------------------------

      //! Check whether port productRequestOut is connected
      //!
      //! \return Whether port productRequestOut is connected
      bool isConnected_productRequestOut_OutputPort(
          NATIVE_INT_TYPE portNum //!< The port number
      );

      //! Check whether port productSendOut is connected
      //!
      //! \return Whether port productSendOut is connected
      bool isConnected_productSendOut_OutputPort(
          NATIVE_INT_TYPE portNum //!< The port number
      );

      //! Check whether port timeGetOut is connected
      //!
      //! \return Whether port timeGetOut is connected
      bool isConnected_timeGetOut_OutputPort(
          NATIVE_INT_TYPE portNum //!< The port number
      );

    PROTECTED:

      // ----------------------------------------------------------------------
      // Port handler base-class functions for special input ports
      //
      // Call these functions directly to bypass the corresponding ports
      // ----------------------------------------------------------------------

      //! Handler base-class function for input port productRecvIn
      void productRecvIn_handlerBase(
          NATIVE_INT_TYPE portNum, //!< The port number
          FwDpIdType id, //!< The container ID
          const Fw::Buffer& buffer, //!< The buffer
          const Fw::Success& status //!< The status
      );

    PROTECTED:

      // ----------------------------------------------------------------------
      // Handlers to implement for typed input ports
      // ----------------------------------------------------------------------

      //! Handler for input port schedIn
      virtual void schedIn_handler(
          NATIVE_INT_TYPE portNum, //!< The port number
          NATIVE_UINT_TYPE context //!< The call order
      ) = 0;

    PROTECTED:

      // ----------------------------------------------------------------------
      // Port handler base-class functions for typed input ports
      //
      // Call these functions directly to bypass the corresponding ports
      // ----------------------------------------------------------------------

      //! Handler base-class function for input port schedIn
      void schedIn_handlerBase(
          NATIVE_INT_TYPE portNum, //!< The port number
          NATIVE_UINT_TYPE context //!< The call order
      );

    PROTECTED:

      // ----------------------------------------------------------------------
      // Pre-message hooks for special async input ports
      //
      // Each of these functions is invoked just before processing a message
      // on the corresponding port. By default, they do nothing. You can
      // override them to provide specific pre-message behavior.
      // ----------------------------------------------------------------------

      //! Pre-message hook for async input port productRecvIn
      virtual void productRecvIn_preMsgHook(
          NATIVE_INT_TYPE portNum, //!< The port number
          FwDpIdType id, //!< The container ID
          const Fw::Buffer& buffer, //!< The buffer
          const Fw::Success& status //!< The status
      );

    PROTECTED:

      // ----------------------------------------------------------------------
      // Pre-message hooks for typed async input ports
      //
      // Each of these functions is invoked just before processing a message
      // on the corresponding port. By default, they do nothing. You can
      // override them to provide specific pre-message behavior.
      // ----------------------------------------------------------------------

      //! Pre-message hook for async input port schedIn
      virtual void schedIn_preMsgHook(
          NATIVE_INT_TYPE portNum, //!< The port number
          NATIVE_UINT_TYPE context //!< The call order
      );

    PROTECTED:

      // ----------------------------------------------------------------------
      // Invocation functions for special output ports
      // ----------------------------------------------------------------------

      //! Invoke output port productRequestOut
      void productRequestOut_out(
          NATIVE_INT_TYPE portNum, //!< The port number
          FwDpIdType id, //!< The container ID
          FwSizeType size //!< The size of the requested buffer
      );

      //! Invoke output port productSendOut
      void productSendOut_out(
          NATIVE_INT_TYPE portNum, //!< The port number
          FwDpIdType id, //!< The container ID
          const Fw::Buffer& buffer //!< The buffer
      );

    PROTECTED:

      // ----------------------------------------------------------------------
      // Functions for managing data products
      // ----------------------------------------------------------------------

      //! Request a data product container
      void Dp_Request(
          ContainerId::T containerId, //!< The container id
          FwSizeType size //!< The buffer size
      );

      //! Send a data product
      void Dp_Send(
          DpContainer& container, //!< The data product container
          Fw::Time timeTag = Fw::ZERO_TIME //!< The time tag
      );

    PROTECTED:

      // ----------------------------------------------------------------------
      // Handlers to implement for data products
      // ----------------------------------------------------------------------

      //! Receive a container of type Container1
      virtual void Dp_Recv_Container1_handler(
          DpContainer& container, //!< The container
          Fw::Success::T status //!< The container status
      ) = 0;

      //! Receive a container of type Container2
      virtual void Dp_Recv_Container2_handler(
          DpContainer& container, //!< The container
          Fw::Success::T status //!< The container status
      ) = 0;

    PROTECTED:

      // ----------------------------------------------------------------------
      // Time
      // ----------------------------------------------------------------------

      //!  Get the time
      //!
      //! \\return The current time
      Fw::Time getTime();

    PRIVATE:

      // ----------------------------------------------------------------------
      // Message dispatch functions
      // ----------------------------------------------------------------------

      //! Called in the message loop to dispatch a message from the queue
      virtual MsgDispatchStatus doDispatch();

    PRIVATE:

      // ----------------------------------------------------------------------
      // Calls for messages received on special input ports
      // ----------------------------------------------------------------------

      //! Callback for port productRecvIn
      static void m_p_productRecvIn_in(
          Fw::PassiveComponentBase* callComp, //!< The component instance
          NATIVE_INT_TYPE portNum, //!< The port number
          FwDpIdType id, //!< The container ID
          const Fw::Buffer& buffer, //!< The buffer
          const Fw::Success& status //!< The status
      );

    PRIVATE:

      // ----------------------------------------------------------------------
      // Calls for messages received on typed input ports
      // ----------------------------------------------------------------------

      //! Callback for port schedIn
      static void m_p_schedIn_in(
          Fw::PassiveComponentBase* callComp, //!< The component instance
          NATIVE_INT_TYPE portNum, //!< The port number
          NATIVE_UINT_TYPE context //!< The call order
      );

    PRIVATE:

      // ----------------------------------------------------------------------
      // Private data product handling functions
      // ----------------------------------------------------------------------

      //! Handler implementation for productRecvIn
      void productRecvIn_handler(
          const NATIVE_INT_TYPE portNum, //!< The port number
          FwDpIdType id, //!< The container id
          const Fw::Buffer& buffer, //!< The buffer
          const Fw::Success& status //!< The buffer status
      );

    PRIVATE:

      // ----------------------------------------------------------------------
      // Special input ports
      // ----------------------------------------------------------------------

      //! Input port productRecvIn
      Fw::InputDpResponsePort m_productRecvIn_InputPort[NUM_PRODUCTRECVIN_INPUT_PORTS];

    PRIVATE:

      // ----------------------------------------------------------------------
      // Typed input ports
      // ----------------------------------------------------------------------

      //! Input port schedIn
      Svc::InputSchedPort m_schedIn_InputPort[NUM_SCHEDIN_INPUT_PORTS];

    PRIVATE:

      // ----------------------------------------------------------------------
      // Special output ports
      // ----------------------------------------------------------------------

      //! Output port productRequestOut
      Fw::OutputDpRequestPort m_productRequestOut_OutputPort[NUM_PRODUCTREQUESTOUT_OUTPUT_PORTS];

      //! Output port productSendOut
      Fw::OutputDpSendPort m_productSendOut_OutputPort[NUM_PRODUCTSENDOUT_OUTPUT_PORTS];

      //! Output port timeGetOut
      Fw::OutputTimePort m_timeGetOut_OutputPort[NUM_TIMEGETOUT_OUTPUT_PORTS];

  };

}

#endif
