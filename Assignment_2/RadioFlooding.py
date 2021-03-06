#
# This class is automatically generated by mig. DO NOT EDIT THIS FILE.
# This class implements a Python interface to the 'RadioFlooding'
# message type.
#

import tinyos.message.Message

# The default size of this message type in bytes.
DEFAULT_MESSAGE_SIZE = 10

# The Active Message type associated with this message.
AM_TYPE = 45

class RadioFlooding(tinyos.message.Message.Message):
    # Create a new RadioFlooding of size 10.
    def __init__(self, data="", addr=None, gid=None, base_offset=0, data_length=10):
        tinyos.message.Message.Message.__init__(self, data, addr, gid, base_offset, data_length)
        self.amTypeSet(AM_TYPE)
    
    # Get AM_TYPE
    def get_amType(cls):
        return AM_TYPE
    
    get_amType = classmethod(get_amType)
    
    #
    # Return a String representation of this message. Includes the
    # message type name and the non-indexed field values.
    #
    def __str__(self):
        s = "Message <RadioFlooding> \n"
        try:
            s += "  [source_id=0x%x]\n" % (self.get_source_id())
        except:
            pass
        try:
            s += "  [seq_num=0x%x]\n" % (self.get_seq_num())
        except:
            pass
        try:
            s += "  [forwarder_id=0x%x]\n" % (self.get_forwarder_id())
        except:
            pass
        try:
            s += "  [bcast_time=0x%x]\n" % (self.get_bcast_time())
        except:
            pass
        try:
            s += "  [counter=0x%x]\n" % (self.get_counter())
        except:
            pass
        return s

    # Message-type-specific access methods appear below.

    #
    # Accessor methods for field: source_id
    #   Field type: int
    #   Offset (bits): 0
    #   Size (bits): 16
    #

    #
    # Return whether the field 'source_id' is signed (False).
    #
    def isSigned_source_id(self):
        return False
    
    #
    # Return whether the field 'source_id' is an array (False).
    #
    def isArray_source_id(self):
        return False
    
    #
    # Return the offset (in bytes) of the field 'source_id'
    #
    def offset_source_id(self):
        return (0 / 8)
    
    #
    # Return the offset (in bits) of the field 'source_id'
    #
    def offsetBits_source_id(self):
        return 0
    
    #
    # Return the value (as a int) of the field 'source_id'
    #
    def get_source_id(self):
        return self.getUIntElement(self.offsetBits_source_id(), 16, 1)
    
    #
    # Set the value of the field 'source_id'
    #
    def set_source_id(self, value):
        self.setUIntElement(self.offsetBits_source_id(), 16, value, 1)
    
    #
    # Return the size, in bytes, of the field 'source_id'
    #
    def size_source_id(self):
        return (16 / 8)
    
    #
    # Return the size, in bits, of the field 'source_id'
    #
    def sizeBits_source_id(self):
        return 16
    
    #
    # Accessor methods for field: seq_num
    #   Field type: int
    #   Offset (bits): 16
    #   Size (bits): 16
    #

    #
    # Return whether the field 'seq_num' is signed (False).
    #
    def isSigned_seq_num(self):
        return False
    
    #
    # Return whether the field 'seq_num' is an array (False).
    #
    def isArray_seq_num(self):
        return False
    
    #
    # Return the offset (in bytes) of the field 'seq_num'
    #
    def offset_seq_num(self):
        return (16 / 8)
    
    #
    # Return the offset (in bits) of the field 'seq_num'
    #
    def offsetBits_seq_num(self):
        return 16
    
    #
    # Return the value (as a int) of the field 'seq_num'
    #
    def get_seq_num(self):
        return self.getUIntElement(self.offsetBits_seq_num(), 16, 1)
    
    #
    # Set the value of the field 'seq_num'
    #
    def set_seq_num(self, value):
        self.setUIntElement(self.offsetBits_seq_num(), 16, value, 1)
    
    #
    # Return the size, in bytes, of the field 'seq_num'
    #
    def size_seq_num(self):
        return (16 / 8)
    
    #
    # Return the size, in bits, of the field 'seq_num'
    #
    def sizeBits_seq_num(self):
        return 16
    
    #
    # Accessor methods for field: forwarder_id
    #   Field type: int
    #   Offset (bits): 32
    #   Size (bits): 16
    #

    #
    # Return whether the field 'forwarder_id' is signed (False).
    #
    def isSigned_forwarder_id(self):
        return False
    
    #
    # Return whether the field 'forwarder_id' is an array (False).
    #
    def isArray_forwarder_id(self):
        return False
    
    #
    # Return the offset (in bytes) of the field 'forwarder_id'
    #
    def offset_forwarder_id(self):
        return (32 / 8)
    
    #
    # Return the offset (in bits) of the field 'forwarder_id'
    #
    def offsetBits_forwarder_id(self):
        return 32
    
    #
    # Return the value (as a int) of the field 'forwarder_id'
    #
    def get_forwarder_id(self):
        return self.getUIntElement(self.offsetBits_forwarder_id(), 16, 1)
    
    #
    # Set the value of the field 'forwarder_id'
    #
    def set_forwarder_id(self, value):
        self.setUIntElement(self.offsetBits_forwarder_id(), 16, value, 1)
    
    #
    # Return the size, in bytes, of the field 'forwarder_id'
    #
    def size_forwarder_id(self):
        return (16 / 8)
    
    #
    # Return the size, in bits, of the field 'forwarder_id'
    #
    def sizeBits_forwarder_id(self):
        return 16
    
    #
    # Accessor methods for field: bcast_time
    #   Field type: int
    #   Offset (bits): 48
    #   Size (bits): 16
    #

    #
    # Return whether the field 'bcast_time' is signed (False).
    #
    def isSigned_bcast_time(self):
        return False
    
    #
    # Return whether the field 'bcast_time' is an array (False).
    #
    def isArray_bcast_time(self):
        return False
    
    #
    # Return the offset (in bytes) of the field 'bcast_time'
    #
    def offset_bcast_time(self):
        return (48 / 8)
    
    #
    # Return the offset (in bits) of the field 'bcast_time'
    #
    def offsetBits_bcast_time(self):
        return 48
    
    #
    # Return the value (as a int) of the field 'bcast_time'
    #
    def get_bcast_time(self):
        return self.getUIntElement(self.offsetBits_bcast_time(), 16, 1)
    
    #
    # Set the value of the field 'bcast_time'
    #
    def set_bcast_time(self, value):
        self.setUIntElement(self.offsetBits_bcast_time(), 16, value, 1)
    
    #
    # Return the size, in bytes, of the field 'bcast_time'
    #
    def size_bcast_time(self):
        return (16 / 8)
    
    #
    # Return the size, in bits, of the field 'bcast_time'
    #
    def sizeBits_bcast_time(self):
        return 16
    
    #
    # Accessor methods for field: counter
    #   Field type: int
    #   Offset (bits): 64
    #   Size (bits): 16
    #

    #
    # Return whether the field 'counter' is signed (False).
    #
    def isSigned_counter(self):
        return False
    
    #
    # Return whether the field 'counter' is an array (False).
    #
    def isArray_counter(self):
        return False
    
    #
    # Return the offset (in bytes) of the field 'counter'
    #
    def offset_counter(self):
        return (64 / 8)
    
    #
    # Return the offset (in bits) of the field 'counter'
    #
    def offsetBits_counter(self):
        return 64
    
    #
    # Return the value (as a int) of the field 'counter'
    #
    def get_counter(self):
        return self.getUIntElement(self.offsetBits_counter(), 16, 1)
    
    #
    # Set the value of the field 'counter'
    #
    def set_counter(self, value):
        self.setUIntElement(self.offsetBits_counter(), 16, value, 1)
    
    #
    # Return the size, in bytes, of the field 'counter'
    #
    def size_counter(self):
        return (16 / 8)
    
    #
    # Return the size, in bits, of the field 'counter'
    #
    def sizeBits_counter(self):
        return 16
    
