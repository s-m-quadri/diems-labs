"""
-----------------------------------
Weekly Assignment: 1
Date: 18th March 2023                    
-----------------------------------
>
>    $ python3 lcd_display.py
>    Enter a string: LCD Display
>     _     ____ ____    ____  _           _             
>    | |   / ___|  _ \  |  _ \(_)___ _ __ | | __ _ _   _ 
>    | |  | |   | | | | | | | | / __| '_ \| |/ _` | | | |
>    | |__| |___| |_| | | |_| | \__ \ |_) | | (_| | |_| |
>    |_____\____|____/  |____/|_|___/ .__/|_|\__,_|\__, |
>                                   |_|            |___/ 
>
-----------------------------------
GitHub: s-m-quadri
Roll: B1/36112, Third Year (AY: 2020-24)
B.Tech, Computer Science and Engineering
"""


import pyfiglet
import re


def main():
    text = LCD_Display()
    print(text)


class LCD_Display:
    def __init__(self, text: str = None) -> None:
        self.text = self.get_text() if text == None else text

    def __str__(self) -> str:
        lcd_figlet = pyfiglet.Figlet(font="standard")
        return lcd_figlet.renderText(self.text)

    def get_text(self):
        while True:
            try:
                raw_text: str = input("Enter a string: ")
                if text := re.search(r"^([\w\s]+)$", raw_text):
                    text = text.group(1)
                else:
                    raise ValueError("Must be alpha numeric!")
                break
            except ValueError as error:
                print(error)
                continue
        return text


if __name__ == "__main__":
    main()
