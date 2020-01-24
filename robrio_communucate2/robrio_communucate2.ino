static const unsigned int INVALID_BALL_DATA = 0xffff;
static const unsigned int MESSAGE_START_CODE = 0xff00;

struct pixyBallData
{
  unsigned int distance;
  int angle;
};

struct pixyData
{
  pixyBallData ball1;
  pixyBallData ball2;
  pixyBallData ball3;
  pixyBallData ball4;
};

struct message
{
  pixyData pixy;
  byte serializer_state; 
  byte safezone_state;  
  int robot_angle; 
  byte DIP_mode;  
  byte checksum;
};              

/*
 * Takes a message structure and convert it to a bytes buffer.
 * msg (in) - The message to convert
 * buffer (out) - The bytes buffer to be filled with the data of msg
 * buffer_size (in) - Size in bytes of the buffer
 * return the number of bytes actually written to the bytes buffer
 */
unsigned int serializeMessage(const message* const msg, byte* buffer, unsigned int buffer_size)
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
