#include <iostream>
#include <string>
using namespace std;

int bit_rev(int n)
{
	        int res=0;
		        int cnt = 4;
			        while (cnt--) {
					                res = (res<<1) | (n&1);
							                n>>=1;
									        }
				        return res;
}

string str_sort(string str)
{
	        int size = str.size();
		        for (int i=0; i<size; i++) {
				                for (int j=i+2; j<size; j=j+2) {
							                        if (str[i]>str[j]) {
											                                char t = str[i];
															                                str[i] = str[j];
																			                                str[j] = t;
																							                        }
										                }
						        }
			        return str;
}

int main()
{
	        string str1, str2;
		        cin>>str1>>str2;
			        string str = str1+str2;

				        str = str_sort(str);

					        for (int i=0; i<str.size(); i++) {
							                int x=0;
									                if (str[i]>='0'&&str[i]<='9')
												                        x = str[i]-'0';
											                else if (str[i]>='a'&&str[i]<='f')
														                        x = str[i]-'a'+10;
													                else if (str[i]>='A'&&str[i]<='F')
																                        x = str[i]-'A'+10;
															                else {
																		                    printf("%c", str[i]);
																				                        continue;
																							                }
																	                int res = bit_rev(x);

																			                if (res >= 10)
																						                        printf("%c", (res-10)+'A');
																					                else
																								                        printf("%d", res);
																							        }
						        printf("\n");
							        return 0;
}
