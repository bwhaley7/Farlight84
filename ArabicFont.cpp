#include "Includes.h"
std::string FuckEnglish(std::string s)
{
    for (int i = 0; i < s.size(); i++) {
        if (s[i] < 'A' || s[i] > 'Z' &&
            s[i] < 'a' || s[i] > 'z')
        {
            s.erase(i, 1);
            i--;
        }
    }
    return s;
}
std::string FuckEnglish2(std::string s)
{
    for (int i = 0; i < s.size(); i++) {
        if (s.find_first_of(("abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ")) != std::string::npos)
        {
            s.erase(i, 1);
            i--;
        }
    }
    return s;
}
std::string wstring_utf8(const std::wstring& wide_string)
{
    if (wide_string.empty()) return "";
    const auto size_needed = WideCharToMultiByte(CP_UTF8, 0, &wide_string.at(0), (int)wide_string.size(), nullptr, 0, nullptr, nullptr);
    if (size_needed <= 0)
        throw std::runtime_error("WideCharToMulitiByte() failded:" + std::to_string(size_needed));
    std::string result(size_needed, 0);
    WideCharToMultiByte(CP_UTF8, 0, &wide_string.at(0), (int)wide_string.size(), &result.at(0), size_needed, nullptr, nullptr);
    return result;
}

std::string ReverseWord(std::string word)
{
    string yheword = "";
    if (iscontentArBIC(word)) {

        string FuckEnglishx = FuckEnglish(word);
        string FuckArabic = FuckEnglish2(word);
        string arab = FarsiType::ConvertToFAGlyphs(FuckArabic);
        yheword = FuckEnglishx.append(arab);
    }
    else yheword = word;
    return yheword;
}

bool iscontentArBIC(std::string str) {
    for (int i = 0; i < str.size(); i++) {
        if (
            str.find(u8"\u0623") != std::string::npos || str.find(u8"\ufe83") != std::string::npos || str.find(u8"\u0623") != std::string::npos || str.find(u8"\ufe84") != std::string::npos || str.find(u8"\ufe84") != std::string::npos
            || str.find(u8"\u0627") != std::string::npos || str.find(u8"\ufe8d") != std::string::npos || str.find(u8"\u0627") != std::string::npos || str.find(u8"\ufe8e") != std::string::npos || str.find(u8"\ufe8e") != std::string::npos
            || str.find(u8"\u0622") != std::string::npos || str.find(u8"\ufe81") != std::string::npos || str.find(u8"\u0622") != std::string::npos || str.find(u8"\ufe82") != std::string::npos || str.find(u8"\ufe82") != std::string::npos
            || str.find(u8"\u0621") != std::string::npos || str.find(u8"\ufe80") != std::string::npos || str.find(u8"\u0621") != std::string::npos || str.find(u8"\u0621") != std::string::npos || str.find(u8"\u0621") != std::string::npos
            || str.find(u8"\u0624") != std::string::npos || str.find(u8"\ufe85") != std::string::npos || str.find(u8"\u0624") != std::string::npos || str.find(u8"\ufe86") != std::string::npos || str.find(u8"\ufe86") != std::string::npos
            || str.find(u8"\u0625") != std::string::npos || str.find(u8"\ufe87") != std::string::npos || str.find(u8"\u0625") != std::string::npos || str.find(u8"\ufe88") != std::string::npos || str.find(u8"\ufe88") != std::string::npos
            || str.find(u8"\u0626") != std::string::npos || str.find(u8"\ufe89") != std::string::npos || str.find(u8"\ufe8b") != std::string::npos || str.find(u8"\ufe8c") != std::string::npos || str.find(u8"\ufe8a") != std::string::npos
            || str.find(u8"\u0628") != std::string::npos || str.find(u8"\ufe8f") != std::string::npos || str.find(u8"\ufe91") != std::string::npos || str.find(u8"\ufe92") != std::string::npos || str.find(u8"\ufe90") != std::string::npos
            || str.find(u8"\u067e") != std::string::npos || str.find(u8"\ufb56") != std::string::npos || str.find(u8"\ufb58") != std::string::npos || str.find(u8"\ufb59") != std::string::npos || str.find(u8"\ufb57") != std::string::npos
            || str.find(u8"\u062A") != std::string::npos || str.find(u8"\ufe95") != std::string::npos || str.find(u8"\ufe97") != std::string::npos || str.find(u8"\ufe98") != std::string::npos || str.find(u8"\ufe96") != std::string::npos
            || str.find(u8"\u0629") != std::string::npos || str.find(u8"\ufe93") != std::string::npos || str.find(u8"\u0629") != std::string::npos || str.find(u8"\u0629") != std::string::npos || str.find(u8"\ufe94") != std::string::npos
            || str.find(u8"\u062b") != std::string::npos || str.find(u8"\ufe99") != std::string::npos || str.find(u8"\ufe9b") != std::string::npos || str.find(u8"\ufe9c") != std::string::npos || str.find(u8"\ufe9a") != std::string::npos
            || str.find(u8"\u062c") != std::string::npos || str.find(u8"\ufe9d") != std::string::npos || str.find(u8"\ufe9f") != std::string::npos || str.find(u8"\ufea0") != std::string::npos || str.find(u8"\ufe9e") != std::string::npos
            || str.find(u8"\u0686") != std::string::npos || str.find(u8"\ufb7a") != std::string::npos || str.find(u8"\ufb7c") != std::string::npos || str.find(u8"\ufb7d") != std::string::npos || str.find(u8"\ufb7b") != std::string::npos
            || str.find(u8"\u062d") != std::string::npos || str.find(u8"\ufea1") != std::string::npos || str.find(u8"\ufea3") != std::string::npos || str.find(u8"\ufea4") != std::string::npos || str.find(u8"\ufea2") != std::string::npos
            || str.find(u8"\u062e") != std::string::npos || str.find(u8"\ufea5") != std::string::npos || str.find(u8"\ufea7") != std::string::npos || str.find(u8"\ufea8") != std::string::npos || str.find(u8"\ufea6") != std::string::npos
            || str.find(u8"\u062f") != std::string::npos || str.find(u8"\ufea9") != std::string::npos || str.find(u8"\u062f") != std::string::npos || str.find(u8"\ufeaa") != std::string::npos || str.find(u8"\ufeaa") != std::string::npos
            || str.find(u8"\u0630") != std::string::npos || str.find(u8"\ufeab") != std::string::npos || str.find(u8"\u0630") != std::string::npos || str.find(u8"\ufeac") != std::string::npos || str.find(u8"\ufeac") != std::string::npos
            || str.find(u8"\u0631") != std::string::npos || str.find(u8"\ufead") != std::string::npos || str.find(u8"\u0631") != std::string::npos || str.find(u8"\ufeae") != std::string::npos || str.find(u8"\ufeae") != std::string::npos
            || str.find(u8"\u0632") != std::string::npos || str.find(u8"\ufeaf") != std::string::npos || str.find(u8"\u0632") != std::string::npos || str.find(u8"\ufeb0") != std::string::npos || str.find(u8"\ufeb0") != std::string::npos
            || str.find(u8"\u0698") != std::string::npos || str.find(u8"\ufb8a") != std::string::npos || str.find(u8"\u0698") != std::string::npos || str.find(u8"\ufb8b") != std::string::npos || str.find(u8"\ufb8b") != std::string::npos
            || str.find(u8"\u0633") != std::string::npos || str.find(u8"\ufeb1") != std::string::npos || str.find(u8"\ufeb3") != std::string::npos || str.find(u8"\ufeb4") != std::string::npos || str.find(u8"\ufeb2") != std::string::npos
            || str.find(u8"\u0634") != std::string::npos || str.find(u8"\ufeb5") != std::string::npos || str.find(u8"\ufeb7") != std::string::npos || str.find(u8"\ufeb8") != std::string::npos || str.find(u8"\ufeb6") != std::string::npos
            || str.find(u8"\u0635") != std::string::npos || str.find(u8"\ufeb9") != std::string::npos || str.find(u8"\ufebb") != std::string::npos || str.find(u8"\ufebc") != std::string::npos || str.find(u8"\ufeba") != std::string::npos
            || str.find(u8"\u0636") != std::string::npos || str.find(u8"\ufebd") != std::string::npos || str.find(u8"\ufebf") != std::string::npos || str.find(u8"\ufec0") != std::string::npos || str.find(u8"\ufebe") != std::string::npos
            || str.find(u8"\u0637") != std::string::npos || str.find(u8"\ufec1") != std::string::npos || str.find(u8"\ufec3") != std::string::npos || str.find(u8"\ufec4") != std::string::npos || str.find(u8"\ufec2") != std::string::npos
            || str.find(u8"\u0638") != std::string::npos || str.find(u8"\ufec5") != std::string::npos || str.find(u8"\ufec7") != std::string::npos || str.find(u8"\ufec8") != std::string::npos || str.find(u8"\ufec6") != std::string::npos
            || str.find(u8"\u0639") != std::string::npos || str.find(u8"\ufec9") != std::string::npos || str.find(u8"\ufecb") != std::string::npos || str.find(u8"\ufecc") != std::string::npos || str.find(u8"\ufeca") != std::string::npos
            || str.find(u8"\u063a") != std::string::npos || str.find(u8"\ufecd") != std::string::npos || str.find(u8"\ufecf") != std::string::npos || str.find(u8"\ufed0") != std::string::npos || str.find(u8"\ufece") != std::string::npos
            || str.find(u8"\u0641") != std::string::npos || str.find(u8"\ufed1") != std::string::npos || str.find(u8"\ufed3") != std::string::npos || str.find(u8"\ufed4") != std::string::npos || str.find(u8"\ufed2") != std::string::npos
            || str.find(u8"\u0642") != std::string::npos || str.find(u8"\ufed5") != std::string::npos || str.find(u8"\ufed7") != std::string::npos || str.find(u8"\ufed8") != std::string::npos || str.find(u8"\ufed6") != std::string::npos
            || str.find(u8"\u06a9") != std::string::npos || str.find(u8"\ufed9") != std::string::npos || str.find(u8"\ufedb") != std::string::npos || str.find(u8"\ufedc") != std::string::npos || str.find(u8"\ufeda") != std::string::npos
            || str.find(u8"\u0643") != std::string::npos || str.find(u8"\ufed9") != std::string::npos || str.find(u8"\ufedb") != std::string::npos || str.find(u8"\ufedc") != std::string::npos || str.find(u8"\ufeda") != std::string::npos
            || str.find(u8"\u06af") != std::string::npos || str.find(u8"\ufb92") != std::string::npos || str.find(u8"\ufb94") != std::string::npos || str.find(u8"\ufb95") != std::string::npos || str.find(u8"\ufb93") != std::string::npos
            || str.find(u8"\u0644") != std::string::npos || str.find(u8"\ufedd") != std::string::npos || str.find(u8"\ufedf") != std::string::npos || str.find(u8"\ufee0") != std::string::npos || str.find(u8"\ufede") != std::string::npos
            || str.find(u8"\u0645") != std::string::npos || str.find(u8"\ufee1") != std::string::npos || str.find(u8"\ufee3") != std::string::npos || str.find(u8"\ufee4") != std::string::npos || str.find(u8"\ufee2") != std::string::npos
            || str.find(u8"\u0646") != std::string::npos || str.find(u8"\ufee5") != std::string::npos || str.find(u8"\ufee7") != std::string::npos || str.find(u8"\ufee8") != std::string::npos || str.find(u8"\ufee6") != std::string::npos
            || str.find(u8"\u0647") != std::string::npos || str.find(u8"\ufee9") != std::string::npos || str.find(u8"\ufeeb") != std::string::npos || str.find(u8"\ufeec") != std::string::npos || str.find(u8"\ufeea") != std::string::npos
            || str.find(u8"\u0648") != std::string::npos || str.find(u8"\ufeed") != std::string::npos || str.find(u8"\ufeed") != std::string::npos || str.find(u8"\ufeee") != std::string::npos || str.find(u8"\ufeee") != std::string::npos
            || str.find(u8"\u06cc") != std::string::npos || str.find(u8"\ufbfc") != std::string::npos || str.find(u8"\ufbfe") != std::string::npos || str.find(u8"\ufbff") != std::string::npos || str.find(u8"\ufbfd") != std::string::npos
            || str.find(u8"\u064a") != std::string::npos || str.find(u8"\ufef1") != std::string::npos || str.find(u8"\ufef3") != std::string::npos || str.find(u8"\ufef4") != std::string::npos || str.find(u8"\ufef2") != std::string::npos
            || str.find(u8"\u0649") != std::string::npos || str.find(u8"\ufeef") != std::string::npos || str.find(u8"\u0649") != std::string::npos || str.find(u8"\ufef0") != std::string::npos || str.find(u8"\ufef0") != std::string::npos
            || str.find(u8"\u0640") != std::string::npos || str.find(u8"\u0640") != std::string::npos || str.find(u8"\u0640") != std::string::npos || str.find(u8"\u0640") != std::string::npos || str.find(u8"\u0640") != std::string::npos
            || str.find(u8"\ufefb") != std::string::npos || str.find(u8"\ufefb") != std::string::npos || str.find(u8"\ufefb") != std::string::npos || str.find(u8"\ufefc") != std::string::npos || str.find(u8"\ufefc") != std::string::npos
            || str.find(u8"\ufef7") != std::string::npos || str.find(u8"\ufef7") != std::string::npos || str.find(u8"\ufef7") != std::string::npos || str.find(u8"\ufef8") != std::string::npos || str.find(u8"\ufef8") != std::string::npos)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}