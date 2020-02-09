static const byte INVALID_BALL_DATA = 0xff;
static const byte MESSAGE_START_CODE_FIRST = 0xff;
static const byte MESSAGE_START_CODE_LAST = 0xfe;

typedef struct 
{
  byte distance;
  int8_t angle;
} PixyBallData;

typedef struct 
{
  PixyBallData ball1;
  PixyBallData ball2;
  PixyBallData ball3;
  PixyBallData ball4;
} PixyData;

typedef struct
{
  PixyData pixy;
  byte serializer_state;
  byte left_distance;
  byte right_distance;
  byte checksum;
} Message;

/*typedef struct
{
  byte high;
  byte low;  
} TwoBytes;
*/
/*
 * Takes a two bytes type (such as an int) and convert it to a high and low bytes. 
 * int_to_convert (in) - the data to separate into two bytes
 * two_bytes (out) - the separated data
 * return true if successfully converted
 */
/*boolean int_to_two_byte(unsigned int int_to_convert, TwoBytes* two_bytes)
{
  if (two_bytes == NULL)
  {
    return false;
  }

  two_bytes->low = (byte)(int_to_convert & 0xff);
  two_bytes->high = (byte)((int_to_convert >> 8 ) & 0xff);
  return true;
}*/

/*
 * Takes a message structure and convert it to a bytes buffer.
 * msg (in) - The message to convert
 * buffer (out) - The bytes buffer to be filled with the data of msg
 * buffer_size (in) - Size in bytes of the buffer
 * return the number of bytes actually written to the bytes buffer
 */
unsigned int serialize_message(const Message* const msg, byte* buffer, unsigned int buffer_size)
{
  if ((msg == NULL) || (buffer == NULL) || (buffer_size < 12))
  {
    return 0;
  }

  buffer[0] = msg->pixy.ball1.distance;
  buffer[1] = msg->pixy.ball1.angle;
  buffer[2] = msg->pixy.ball2.distance;
  buffer[3] = msg->pixy.ball2.angle;
  buffer[4] = msg->pixy.ball3.distance;
  buffer[5] = msg->pixy.ball3.angle;
  buffer[6] = msg->pixy.ball4.distance;
  buffer[7] = msg->pixy.ball4.angle;
  buffer[8] = msg->serializer_state;
  buffer[9] = msg->left_distance;
  buffer[10] = msg->right_distance;
  buffer[11] = msg->checksum;
  return sizeof(Message);
}

void setup()
{
  Serial.begin(9600);
}



void loop()
{
  static Message msg;
  static byte buffer[sizeof(Message)];

  /*
  * TODO: Fill msg using all the other arduino functions to read from the sensors.
  */

  unsigned int bytes_written = serialize_message(&msg, buffer, sizeof(buffer));
  Serial.write(buffer, bytes_written); 
  Serial.println(Serial.read(), DEC);
}
