# Gemini 2.5 Animal Guessing Game

A C++ console application that uses the Google Gemini 2.5 Flash API to play a game of "10 Questions." The AI acts as the game master, holding a secret animal and providing hints based on user input.

## Features
- **AI-Powered Logic:** Uses Gemini 2.5 Flash to understand and respond to natural language questions.
- **REST Integration:** Built using `libcpr` for network requests and `nlohmann-json` for data parsing.
- **Modern C++:** Utilizes C++20 features like `std::format`.

## Prerequisites
- **Compiler:** MSVC (Visual Studio 2022) or any C++20 compatible compiler.
- **Package Manager:** `vcpkg` (for installing `cpr` and `nlohmann-json`).
- **API Key:** A valid Google Gemini API Key from [Google AI Studio](https://aistudio.google.com/).

## Installation
1. Clone the repository.
2. Install dependencies via vcpkg:
   ```bash
   vcpkg install cpr nlohmann-json
