class Wheel {
  private:
      int enable;
      int inHigh;
      int inLow;
      int default_speed = 100;

  public:
    Wheel(int enable, int inHigh, int inLow);

    void setSpeed(int speed);
        
    void forward(int speed);

    void backward(int speed);

    void stop();
};