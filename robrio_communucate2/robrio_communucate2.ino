static const unsigned int INVALID_BALL_DATA = 0xffff;
static const unsigned int MESSAGE_START_CODE = 0xff00;

struct PixyBallData
{
  unsigned int distance;
  int angle;
};

struct PixyData
{
  PixyBallData ball1;
  PixyBallData ball2;
  PixyBallData ball3;
  PixyBallData ball4;
};

struct Message
{
  PixyData pixy;
  byte serializer_state;
  byte safezone_state;
  int robot_angle;
  byte DIP_mode;
  byte checksum;
};

struct TwoBytes
{
  byte high;
  byte low;  
};

void int_to_two_byte(unsigned int int_to_convert, TwoBytes* )
{
  
}

/*
 * Takes a message structure and convert it to a bytes buffer.
 * msg (in) - The message to convert
 * buffer (out) - The bytes buffer to be filled with the data of msg
 * buffer_size (in) - Size in bytes of the buffer
 * return the number of bytes actually written to the bytes buffer
 */
unsigned int serialize_message(const Message* const msg, byte* buffer, unsigned int buffer_size)
{
  // TODO: Implement!
   
  return 0;
}

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop()
{
  // put your main code here, to run repeatedly:
  unsigned int PMValue = analogRead(A0);
  Serial.write(PMValue);
}
