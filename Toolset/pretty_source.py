#
#   atom库中的代码大量为建模工具生成
#   这个脚本可以删除其中以 //Begin //TODO //End //@generated开始的行
#
#   chenqiang01@7aurora.com
#   Jan 22, 2014
#

import sys
import os
import pdb

def is_filtered(line):
    """
    确定一行是否需要删除
    """
    filter_list = ['//Begin', '//TODO', '//End', '//@generated']
    line = line.lstrip()
    for filter in filter_list:
        if line.startswith(filter):
            return True
    return False
    
def pretty_text(text_lines):
    """
    处理所有行
    """
    text_new = []    
    #empty_line_num = 0 # 多个空行以一个空行代替
    for line in text_lines:
        if not is_filtered(line):
            text_new.append(line)
    return text_new

def pretty_file(file_name):
    """
    处理文件
    """
    
    # 先读取所有行
    text_lines = []
    with open(file_name, 'r') as fp:
        text_lines = fp.readlines()    
    text_lines = pretty_text(text_lines)
    
    #print(file_name.split('/')[-1])    
    #for line in text_new:
    #    print(line)
    
    # 写入所有行
    with open(file_name, 'w') as fp:
        fp.writelines(text_lines)

def pretty_dir(root_dir):
    """
    递归处理目录
    """
    process_num = 0
    for root, sub_folders, files in os.walk(root_dir):
        print(root.split('/')[-1])
        for file_name in files:
            file_ext = os.path.splitext(file_name)[1]
            if file_ext == '.h' or file_ext == '.cpp':
                print('\t', file_name)
                pretty_file(root + '/' + file_name)
                process_num = process_num + 1
    print(process_num, 'file processed.')

if __name__ == '__main__':
    dir_name = '../3rdParty/atom'
    if len(sys.argv) > 1:
        dir_name = sys.argv[1]
    pretty_dir(dir_name)
    