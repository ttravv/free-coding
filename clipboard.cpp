// https://leetcode.com/problems/2-keys-keyboard/description/

#include <iostream>
using namespace std;

int minSteps(int n) {
  int screen = 1, clipboard = 0, steps = 0;

  if(n == 1) return 0;
  while(screen != n){
      if (clipboard == 0) {
        clipboard = screen;
      }
      else if(clipboard == screen){
        screen += clipboard;
      }
      else if (clipboard != screen && clipboard != 0) {
        if (screen + clipboard == n){
          screen += clipboard;
          
        }
        else if(screen + clipboard < n) {
          
          if ((n - screen) % (screen) == 0) {
            clipboard = screen;

          }
          
          else{
            screen += clipboard;
          }
        }
      }
      
    steps += 1;
  }

  
  return steps;
}


int main() {
  int n = 1; //
  cout << minSteps(n);

  
  return 0;
}