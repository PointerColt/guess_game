# Gemini 2.5 Animal Guessing Game

A C++ console application that uses the Google Gemini 2.5 Flash API to play a game of "10 Questions." The AI acts as the game master, holding a secret animal and providing hints based on user input.

## Features
- **AI-Powered Logic:** Uses Gemini 2.5 Flash to understand and respond to natural language questions.
- **REST API Integration:** Built using `libcpr` for network requests and `nlohmann-json` for data parsing.
- ** Built With Modern C++:** Utilizes C++20 features like `std::format`.

## Prerequisites
- **Compiler:** MSVC (Visual Studio 2022) or any C++20 compatible compiler.
- **Package Manager:** `vcpkg` (for installing `cpr` and `nlohmann-json`).
- **API Key:** A valid Google Gemini API Key from [Google AI Studio](https://aistudio.google.com/).

## Installation
1. Clone the repository :- git clone https://github.com/PointerColt/guess_game.git cd guess_game
   
2. Install dependencies via vcpkg :- vcpkg install cpr nlohmann-json

3. Setup API Key -> Do NOT hardcode your API key in the source code Set it as an environment variable:

//......................for window................................//   
Windows (Command Prompt) : set GEMINI_API_KEY=your_api_key_here
Windows (PowerShell) : $env:GEMINI_API_KEY="your_api_key_here"

//.....................for Linux / Mac............................//
export GEMINI_API_KEY=your_api_key_here


## Built and Run 
1.Create built folder : mkdir build
                        cd build
2.configure project : cmake ..
3.Build : cmake __build .
4../Debug/Guessgame.exe


## What I learned
1.Integrating APIs in C++
2.Making HTTP requests using cpr
3.Parsing JSON with nlohmann-json
4.Using CMake for project management
5.Using Git and GitHub for version control

## Notes
->API rate limits may cause 429 errors
->Requires active internet connection
->Make sure dependencies are correctly installed



