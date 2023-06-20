#pragma once

static const ImWchar ranges[] = {
0x0020, 0x00FF, // Basic Latin
0x0600, 0x06FF,
0x2010, 0x205E,
0XFB50, 0XFBFF,
0XDE00, 0XFEFF,
0
};
std::string FuckEnglish(std::string s);
std::string FuckEnglish2(std::string s);
std::string wstring_utf8(const std::wstring& str);
std::string ReverseWord(std::string word);
bool iscontentArBIC(std::string str);