import os


def destroy_dir(cur_dir):
    onlyefiles = [f for f in os.listdir(cur_dir) if os.path.isfile(os.path.join(cur_dir, f))]
    onlyedirs = [f for f in os.listdir(cur_dir) if os.path.isdir(os.path.join(cur_dir, f))]

    for f in onlyefiles:
        if '.' not in f:
            os.remove(os.path.join(cur_dir,f))
    
    for d in onlyedirs:
        if d[0] == '.':
            continue
        destroy_dir(os.path.join(cur_dir, d))


destroy_dir(os.getcwd())