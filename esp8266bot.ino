#include <ESP8266WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include "addintionally.h"

X509List cert(TELEGRAM_CERTIFICATE_ROOT);
WiFiClientSecure secured_client;

UniversalTelegramBot bot{BOT_TOKEN, secured_client};

void handleMessages(unsigned countOfNewMessages);

void setup(){
  WiFi.begin(SSID, PASSWORD);
  secured_client.setTrustAnchors(&cert);
  while(WiFi.status() != WL_CONNECTED)
    delay(500);
  configTime(0, 0, "pool.ntp.org"); 
  time_t now = time(nullptr);
  while (now < 24 * 3600)
  {
    delay(500);
    now = time(nullptr);
  }
}

void loop(){
  if( !(millis() % 1000) ){
    unsigned countOfNewMessages = bot.getUpdates(bot.last_message_received + 1);
    while(countOfNewMessages){
      handleMessages(countOfNewMessages);
      countOfNewMessages = bot.getUpdates(bot.last_message_received + 1);
    }
  }  
}

void handleMessages(unsigned countOfNewMessages){
  for(unsigned i{0}; i < countOfNewMessages; ++i ){    
    telegramMessage& msg = bot.messages[i];
    
    if(msg.text[0] != '/') continue;

    if(msg.text == "/start")
      bot.sendMessageWithReplyKeyboard(msg.chat_id, "Thanks, " + msg.from_name, "", createKeyboardJson(lessons), true);
  
    else if(short index{ getIndexOfLessonArray(msg.text.substring(1)) }; index != -1)
      if(lessons[index][0].startsWith("GitHub"))
        bot.sendMessage(msg.chat_id, "Owner : " + lessons[index][1] + "\nURL : " + lessons[index][2]);
      else                     
        bot.sendMessage(msg.chat_id, "Conference ID : " + lessons[index][1] + "\nAccess code : " + lessons[index][2] + "\nURL : " + lessons[index][3]);  
    
  }
}




