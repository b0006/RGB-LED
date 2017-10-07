#define red_led 2
#define green_led 3
#define blue_led 4

//ФУНКЦИЯ ВЫПОЛНЯЕТСЯ ОДИН РАЗ
void setup()
{
	//УСТАНАВЛИВАЕМ ПИНЫ ДИОДОВ НА ВЫХОД
	pinMode(red_led, OUTPUT);
	pinMode(green_led, OUTPUT);
	pinMode(blue_led, OUTPUT);
	
	//УСТАНАВЛИВАЕМ НАЧАЛЬНОЕ ЗНАЧЕНИЕ
	analogWrite(red_led, 255);
	analogWrite(green_led, 255);
	analogWrite(blue_led, 255);
	
	//СКОРОСТЬ ПЕРЕДАЧИ БИТОВ
	Serial.begin(9600);
}

//ФУНКЦИЯ ВЫПОЛНЯЕТСЯ БЕСКОНЕЧНО ПО ЦИКЛУ
void loop()
{
	//ЕСЛИ ПЕРЕДАЧА ДОСТУПНА - ЗНАЧИТ ЧИТАЕМ ЗНАЧЕНИЯ ИЗ COM-ПОРТА
	if (Serial.available()){
		char led_specifier = Serial.read();
	
	//СОХРАНЯЕМ ЗНАЧЕНИЕ В ПЕРЕМЕННУЮ
	String led_brightness = Serial.readString();
	
	//ВЫЗОВ ФУНКЦИИ
	write_leds(led_specifier, led_brightness);
  }
}

//ПЕРЕДАЧА КОМАНДЫ НА COM-ПОРТ
	//r - команда красному диоду
	//g - команда зеленному диоду
	//b - комманда синему диоду
void write_leds(char led, String bri)
{
	int brightness = bri.toInt();
	
	if (led == 'r'){
		analogWrite(red_led, 255 - brightness);
		return;
	}
	if (led == 'g'){
		analogWrite(green_led, 255 - brightness);
		return;
	}
	if (led == 'b'){
		analogWrite(blue_led, 255 - brightness);
		return;
	}
	return;
}


