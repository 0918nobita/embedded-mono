env = Environment(CPPFLAGS='-Wall -Wextra')
env.ParseConfig('pkg-config --cflags --libs mono-2')
env.Program(target='bin/main', source=['main.cpp'])
