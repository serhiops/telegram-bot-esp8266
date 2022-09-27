

const String BOT_TOKEN{ "your token for bot" };
const String SSID{ "" };
const String PASSWORD{ "" };

constexpr short ROWS{ 11 };
constexpr short COLS{ 4 };
String lessons[ROWS][COLS]{
  {"Фізика", "436 136 4793", "123456", ""}, 
  {"Математика", "829 2974 8682", "65vYj8", "https://us04web.zoom.us/j/82929748682?pwd=VERJUjhaeXorSnpnZEk3RHF4TmE0QT09"},
  
  {"Історія", "927 370 7575", "9D5Wkt", "https://us04web.zoom.us/j/9273707575?pwd=ejVLd0RnTXBNTG1jeGhQbmdOaWF2UT09"},
  {"Програмування", "818 9422 9858", "123171", "https://us02web.zoom.us/j/81894229858?pwd=a0NhbTZUdzk2UlJlc0h1QmZycjhuUT09"},
  
  {"Технології ", "749 688 4849", "ktkt2022", "https://us05web.zoom.us/j/7496884849?pwd=dGJ0UDlUdXhENUlsS2VKeGRzMzZUdz09"}, 
  {"укр/укр.лит", "667 913 6542", "6ujZyX", "https://zoom.us/j/6679136542?pwd=WTlzaHl6RUtEN3dReWFBTXIzOHo5Zz09"},
  
  {"Фізична культура", "865 117 9928", "7758", "https://us04web.zoom.us/j/8651179928?pwd=pFXVMgwQvhaCpJ25hbkNVDNIQalQ9k.1"},
  {"Інформатика", "891 4331 6993", "2101", "https://us05web.zoom.us/j/89143316993?pwd=dFV0Lys5dis5Q0kvaHE5TDJ2Z2ZjUT09"},

  {"Право", "", "", "https://us04web.zoom.us/j/6596108483?pwd=ZTVweC9rNmVFZW1zNmdkTXExVG8yUT09"}, 
  {"Англ.мова(I підгупа)", "999 0811 0870", "2101", "https://us05web.zoom.us/j/99908110870?pwd=dkhlbTVIZEE0RWdTd05HRnNmNHVhZz09 "}, 

  {"GitHub repository", "serhiops", "link", "" },  
}; 

short getIndexOfLessonArray(const String& text);
String createKeyboardJson(String (*arr)[COLS]);