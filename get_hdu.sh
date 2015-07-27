#########################################################################
# File Name: get_hdu.sh
# Author: Netcan
# Blog: http://www.netcan.xyz
# mail: 1469709759@qq.com
# Created Time: 2015-07-01 Sat 9:27:25 CST
#########################################################################
#!/bin/bash


case $1 in
-*)
echo "############################################################
#  每次写题解的时候，都要手动复制题目到博客上，不仅浪费时间也乏味。
#  这本来就是机器能干的事情，所以我把这个脚本写了出来，可以专心刷题了。
#  主要作用是提取题目关键信息（描述，输入输出数据），生成html（这个等写好了在传上来，先给核心部分）。
#  具体请看： http://www.netcan.xyz/?p=394
#  用法: $0 hdu题目编号
############################################################"
	exit
	;;
esac


Q=/tmp/q.html
curl http://acm.hdu.edu.cn/showproblem.php?pid=$1 > $Q
dos2unix -n $Q $Q &> /dev/null
iconv -f gb2312 -t utf-8 $Q -o $Q
# sed -i 's/..\/data/http:\/\/acm.hdu.edu.cn\/data/g' $Q
sed  -i 's/\(.*\)\(<center><img src=..\/data\/images\/.*jpg><\/center>\)\(.*\)/\1\3/g' $Q
ProblemDes=$(sed -n 's/.*Problem Description<\/div> <div class=panel_content>\(.*\)<\/div><div class=panel_bottom>&nbsp;<\/div><br><div class=panel_title align=left>Input.*/\1/p' $Q)
Input=$(sed -n 's/.*Input<\/div> <div class=panel_content>\(.*\)<\/div><div class=panel_bottom>&nbsp;<\/div><br><div class=panel_title align=left>Output.*/\1/p' $Q)
Output=$(sed -n 's/.*Output<\/div> <div class=panel_content>\(.*\)<\/div><div class=panel_bottom>&nbsp;<\/div><br><div class=panel_title align=left>Sample Input.*/\1/p' $Q)
sed -i 's/<pre><div style="font-family:Courier New,Courier,monospace;">/<pre><div style="font-family:Courier New,Courier,monospace;">\n/g' $Q
sed -i 's/<\/div><\/pre>/\n<\/div><\/pre>/g' $Q
begin=$(sed -n '/Sample Input/=' $Q)
end=$(sed -n '/Sample Output/=' $Q)
SampleInput=$(head -n $((end-1)) $Q|tail -n $((end-begin-1)))
begin=$end
end=$(sed -n '/note\.php/=' $Q)
hint=$(sed -n '/Hint/=' $Q)
if (($hint < $end))
then
	end=$hint
fi
SampleOutput=$(head -n $((end-1)) $Q|tail -n $((end-begin-1)))

# echo -e "\e[45m题目描述\e[0m:\n$ProblemDes"
# echo -e "\e[45m输入格式:\e[0m\n$Input"
# echo -e "\e[45m输出格式:\e[0m\n$Output"
# echo -e "\e[45m输入样例:\e[0m\n$SampleInput"
# echo -e "\e[45m输出样例:\e[0m\n$SampleOutput"

SampleInput=$(echo "$SampleInput" | sed ':a;N;$!ba;s/\n/<br>/g')
SampleOutput=$(echo "$SampleOutput" | sed ':a;N;$!ba;s/\n/<br>/g')

# 生成自定义风格网页
OutputFile=./$1.html
echo '<p>题目地址：<a href="http://acm.hdu.edu.cn/showproblem.php?pid='$1'" target="_blank" textvalue="http://acm.hdu.edu.cn/showproblem.php?pid='$1'">http://acm.hdu.edu.cn/showproblem.php?pid='$1'</a></p>
<p>
	<span style="color: rgb(124, 169, 237); font-family: Arial; font-size: 22px; font-weight: bold;">Problem Description</span>
</p>
<p class="ojbox content">
'$ProblemDes'</p>
<p>
	<span style="color: rgb(124, 169, 237); font-family: Arial; font-size: 22px; font-weight: bold;"></span><span style="color: rgb(124, 169, 237); font-family: Arial; font-size: 22px; font-weight: bold;">Input</span>
</p>
<p class="ojbox content">
'$Input'</p>
<p>
	<span style="color: rgb(124, 169, 237); font-family: Arial; font-size: 22px; font-weight: bold;">Output</span>
</p>
<p class="ojbox content">
'$Output'</p>
<p>
	<span style="color: rgb(124, 169, 237); font-family: Arial; font-size: 22px; font-weight: bold;">Sample Input</span>
</p>
<p class="ojbox">
'"$SampleInput"'</p>
<p>
	<span style="color: rgb(124, 169, 237); font-family: Arial; font-size: 22px; font-weight: bold;">Sample Output</span>
</p>
<p class="ojbox">
'"$SampleOutput"'</p>
<p>
	<span style="color: rgb(124, 169, 237); font-family: Arial; font-size: 22px; font-weight: bold;">思路</span>
</p><!--more-->
<p class="ojbox content">

</p>
<p>
	<span style="color: rgb(124, 169, 237); font-family: Arial; font-size: 22px; font-weight: bold;"></span><span style="color: rgb(124, 169, 237); font-family: Arial; font-size: 22px; font-weight: bold;">AC代码</span>
</p>
<pre class="lang:c++ decode:true">
</pre>' | xsel -b -i
# sudo apt-get install xsel
