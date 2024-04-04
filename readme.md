Simple Encryptor Hack The Box

**CHALLENGE DESCRIPTION**
On our regular checkups of our secret flag storage server, we found out that we were hit by ransomware! The original flag data is nowhere to be found, but luckily we not only have the encrypted file but also the encryption program itself.

**Solution**
A zip file and password to unzip it was provided for this CTF. I unzipped the files using the command **unzip Simple\ Encryptor.zip** while passing in the password provided on the bug bounty.


This provided two files: an *encrypt* and *flag.enc* file.  I tried running the encrypted file as it is an executable using the command **./encrypt** but I was getting a *segmentation fault error*.

I decided to disassemble the encryption program using ghidra. While searching for the main function and discovered that the program was written in the c programming language.


I copied the main function to a separate file which I named **MAIN.C** and opened it in vscode (you can use your preferred editor). After reading through the code I understood how the encryption worked. The encryptor was doing an **XOR operation** and then performing a **right shift bitwise operation**.

To reverse the process I needed to perform a **left shift bitwise operation** and then perform an **XOR operation** but to do that I had to run the random function which required a seed.

To locate the seed I saw that the local_18 variable on the main function was used to open the *flag.enc* file which had a seed as the first 4 bits. I then rewrote the code to reverse the encryption while renaming some of the variables to make the code more readable. The reverse engineering code is located on the **exploit.c** file and after running it I got the flag.










