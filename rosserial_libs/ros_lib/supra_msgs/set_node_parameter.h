#ifndef _ROS_SERVICE_set_node_parameter_h
#define _ROS_SERVICE_set_node_parameter_h
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include "ros/msg.h"

namespace supra_msgs
{

static const char SET_NODE_PARAMETER[] = "supra_msgs/set_node_parameter";

  class set_node_parameterRequest : public ros::Msg
  {
    public:
      typedef const char* _nodeId_type;
      _nodeId_type nodeId;
      typedef const char* _parameterId_type;
      _parameterId_type parameterId;
      typedef const char* _value_type;
      _value_type value;

    set_node_parameterRequest():
      nodeId(""),
      parameterId(""),
      value("")
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      uint32_t length_nodeId = strlen(this->nodeId);
      varToArr(outbuffer + offset, length_nodeId);
      offset += 4;
      memcpy(outbuffer + offset, this->nodeId, length_nodeId);
      offset += length_nodeId;
      uint32_t length_parameterId = strlen(this->parameterId);
      varToArr(outbuffer + offset, length_parameterId);
      offset += 4;
      memcpy(outbuffer + offset, this->parameterId, length_parameterId);
      offset += length_parameterId;
      uint32_t length_value = strlen(this->value);
      varToArr(outbuffer + offset, length_value);
      offset += 4;
      memcpy(outbuffer + offset, this->value, length_value);
      offset += length_value;
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      uint32_t length_nodeId;
      arrToVar(length_nodeId, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_nodeId; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_nodeId-1]=0;
      this->nodeId = (char *)(inbuffer + offset-1);
      offset += length_nodeId;
      uint32_t length_parameterId;
      arrToVar(length_parameterId, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_parameterId; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_parameterId-1]=0;
      this->parameterId = (char *)(inbuffer + offset-1);
      offset += length_parameterId;
      uint32_t length_value;
      arrToVar(length_value, (inbuffer + offset));
      offset += 4;
      for(unsigned int k= offset; k< offset+length_value; ++k){
          inbuffer[k-1]=inbuffer[k];
      }
      inbuffer[offset+length_value-1]=0;
      this->value = (char *)(inbuffer + offset-1);
      offset += length_value;
     return offset;
    }

    const char * getType(){ return SET_NODE_PARAMETER; };
    const char * getMD5(){ return "11e9e16ce02e6e9cf155d19a50f67220"; };

  };

  class set_node_parameterResponse : public ros::Msg
  {
    public:
      typedef bool _wasValid_type;
      _wasValid_type wasValid;

    set_node_parameterResponse():
      wasValid(0)
    {
    }

    virtual int serialize(unsigned char *outbuffer) const
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_wasValid;
      u_wasValid.real = this->wasValid;
      *(outbuffer + offset + 0) = (u_wasValid.base >> (8 * 0)) & 0xFF;
      offset += sizeof(this->wasValid);
      return offset;
    }

    virtual int deserialize(unsigned char *inbuffer)
    {
      int offset = 0;
      union {
        bool real;
        uint8_t base;
      } u_wasValid;
      u_wasValid.base = 0;
      u_wasValid.base |= ((uint8_t) (*(inbuffer + offset + 0))) << (8 * 0);
      this->wasValid = u_wasValid.real;
      offset += sizeof(this->wasValid);
     return offset;
    }

    const char * getType(){ return SET_NODE_PARAMETER; };
    const char * getMD5(){ return "250f1d92d459f05d737090c640b109ad"; };

  };

  class set_node_parameter {
    public:
    typedef set_node_parameterRequest Request;
    typedef set_node_parameterResponse Response;
  };

}
#endif
