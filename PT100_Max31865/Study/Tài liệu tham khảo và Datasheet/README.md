### Note Về biểu thức tính nhiệt độ

- RRTD = R(T) = R0 (1 + aT + bT^2 + c(T-100)T^3)

> Với R0 = 100 ohm (điện trở ngõ ra của PT100 khi ở nhiệt độ 0 độ C)

> Với a = 3.90830 x 10^(-3)

> với b = -5.77500 x 10^(-7)

> Với c = 0 khi đo nhiệt độ trong đoạn [0;850]

> Với c = -4.18301 x 10^(-12) khi đo nhiệt độ trong đoạn [-200;0] 

- RRTD = [(ADC code) x RREF] / 2^15

> Với ADC code là data thu đc từ max31865 -> chuyển sang số thực

> với RREF = 430 ohm (Với PT100 thì là 430 ohm, với PT1000 thì sẽ là 4300 ohm)


### Tham Khảo

- Đây là một số thư viện và trang web tôi đã tham khảo

> https://learn.adafruit.com/adafruit-max31865-rtd-pt100-amplifier

> https://github.com/4ilo/MAX31865-Stm32HAL

> https://github.com/steve71/MAX31865/blob/master/max31865.py


- Một số trang tham khảo vui:

> http://andybrown.me.uk/2018/02/11/max31865-rtd/

> https://www.youtube.com/watch?v=1U4fep_qAeo

> https://www.instructables.com/id/Reading-Temperature-From-PT100-Using-Arduino/