
short getIndexOfLessonArray(const String& text){
    for(unsigned short i{0}; i < ROWS; ++i){
      if(lessons[i][0] == text){
        return i;                
      }      
    }
    return -1;    
}

String createKeyboardJson(String (*arr)[COLS]){
    String str = "[";
    for(short i{0}; i < ROWS; i += 2){
        if(i + 1 >= ROWS)
          str += "[\"/" + arr[i][0] +  "\"]";
        else
          str += "[\"/" + arr[i][0] + "\", \"/" + arr[i + 1][0] + "\"]" + (i < ROWS - 2?",":"");  
    }
    str += "]";
    return str;  
}