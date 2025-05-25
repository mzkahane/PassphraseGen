# PassphraseGen

PassphraseGen is a simple C program that generates secure passphrases similar to those created by the diceware method. It uses a customizable wordlist and simulates dice rolls to select words, allowing users to tailor the number of words, the separator between words, and whether the last word is replaced by a number.

## Features

- Customizable number of words in the passphrase
- User-defined separator between words
- Option to replace the last word with a random number
- Uses a simple, memorable wordlist for ease of recall
- Fast, with no external dependencies

## Why PassphraseGen?

Unlike other passphrase generators, PassphraseGen focuses on speed and simplicity, using a straightforward wordlist and offering a high level of user customization. It is designed for users who want memorable, secure passphrases without unnecessary complexity.

## Installation & Usage

PassphraseGen is a standalone C project with no dependencies beyond what is included in the repository.

1. **Clone the repository:**
   ```
   git clone https://github.com/yourusername/PassphraseGen.git
   ```
2. **Build the project:**
   ```
   cd PassphraseGen
   make
   ```
3. **Run the program:**
   ```
   ./generator [options]
   ```
Options allow you to specify the number of words, the separator, and whether to replace the last word with a number.

## Wordlist

PassphraseGen uses the EFF short wordlist for generating passphrases:  
[EFF Short Wordlist](https://www.eff.org/files/2016/09/08/eff_short_wordlist_1.txt)

![password_strength](https://github.com/user-attachments/assets/193a046e-9630-40e3-8e1f-1754bfc7412d)

## Author

Matthew Kahane (GitHub: [mzkahane](https://github.com/mzkahane))
