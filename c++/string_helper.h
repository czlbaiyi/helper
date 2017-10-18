/*********************************************************************
 * Created:       2017/10/18
 * File name:     string_helper.h
 * Author:        ChenZhonglin
 * Revision:      1.0.0
 *
 * Copyright (C)  2017 - 2020 , All Rights Reserved.
 *
 * Purpose: 
 *********************************************************************/

 #ifndef __STRING_HELPER_H_2017_10_18__
 #define __STRING_HELPER_H_2017_10_18__
 
 #include <vector>
 #include <string>
 #include <sstream>
 
 namespace StringHelper
 {
	 /** 注，只对原生类型管用 */
	 /** 把数值类型转换成字符串 */
	 template <typename T>
	 inline std::string  to_string(T type)
	 {
		 std::ostringstream  stream;
		 //stream<< std::setprecision(12);
		 stream << type;
		 return stream.str();
	 }
	 /** 注，只对原生类型管用 */
	 //-返回一个带正负号的string
	 template <typename T>
	 inline std::string to_symbol_string(T type)
	 {
		 std::ostringstream  stream;
		 stream << type;
		 if (type < 0)
			 return stream.str();
		 else
			 return "+" + stream.str();
	 }
	 /** 注，只对原生类型管用 */
	 /** 字符串转到 long long  */
	 inline long long  to_longlong(const std::string& val_str)
	 {
		 long long val;
		 std::stringstream  stream;
		 stream << val_str;
		 stream >> val;
		 return val;
	 }
	 /** 注，只对原生类型管用 */
	 /** 字符串转到 float  */
	 inline float  to_float(const std::string& val_str)
	 {
		 float val;
		 std::stringstream  stream;
		 stream << val_str;
		 stream >> val;
		 return val;
	 }
	 /** 注，只对原生类型管用 */
	 /** 字符串转到 int  */
	 inline int  to_int(const std::string& val_str)
	 {
		 int val;
		 std::stringstream  stream;
		 stream << val_str;
		 stream >> val;
		 return val;
	 }
 
	 template<typename T>
	 inline std::vector<T> ParseString(std::string strData, std::string separatorFlag)
	 {
		 std::vector<T> DataVec;
		 int pos = 0;
		 int size = strData.size();
		 while (pos < size)
		 {
			 int findpos = strData.find(separatorFlag, pos);
			 if (findpos == std::string::npos)
			 {
				 findpos = size;
			 }
			 std::string singleStrData = strData.substr(pos, findpos - pos);
			 pos = ++findpos;
 
			 T temp;
			 std::stringstream  stream;
			 stream << singleStrData;
			 stream >> temp;
			 DataVec.push_back(temp);
		 }
		 return DataVec;
	 }
 
	 /** 注，只对原生类型管用 */
	 template<typename T>
	 inline std::string VecToString(std::vector<T> vec, std::string separatorFlag){
		 std::string str = "";
		 for (int i = 0; i < (int)vec.size(); ++i)
		 {
			 if (i != 0)
			 {
				 str += separatorFlag;
			 }
			 str += StringHelper::to_string(vec[i]);
		 }
		 return str;
	 }
 }
 
 #endif
 