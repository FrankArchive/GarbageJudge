#include"LanguageConfig.h"
#include"SyscallLayer.h"
using namespace std;
//���������ʽ:��ʽ���ַ����е�һ��%s����Դ�ļ����ƣ��ڶ���%s��������ļ�����
void initCommands() {
	compile_commands[CPP] = 
		"g++ %s -Wall -static -std=c++11 -DONLINE_JUDGE -fno-asm -O2 -o %s";

	//JAVA�Ͳ�һ��,�ļ���������Main.java,������������%sҪ��Ȼ�ͱ��˰��ڵ���ܳ
	compile_commands[JAVA] =
		"javac -J-Xms32m -J-Xmx256m -encoding UTF-8 %s#%s";

	compile_commands[PASCAL] =
		"fpc %s -Cs32000000 -Sh -O2 -Co -Ct -Ci -o%s";
}

void initRegexCE() {
	match_compile_error[CPP] = "\w";
	match_compile_error[JAVA] = "\w";
	match_compile_error[PASCAL] = "Error:";
}

langtype tellType(string fn) {
	fn = fn.substr(fn.find('.') == -1 ? 0 : fn.find('.'));
	if (fn == "cpp")return CPP;
	if (fn == "java")return JAVA;
	if (fn == "pas")return PASCAL;
	return NOT_SUPPORTED;
}
void bootBin(langtype & lang, string & file) {
	ptrace(PTRACE_TRACEME, 0, NULL, NULL);
	switch (lang) {
	case CPP:
		execl(file.c_str(), file.c_str(), nullptr);
		break;
	case JAVA:
		execl("java", file.c_str(), nullptr);
		break;
	}///////////////////////////////////////////////////
}