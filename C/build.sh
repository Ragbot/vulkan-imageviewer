/usr/bin/glslc ./shaders/simple_shader.frag -o ./shaders/simple_shader.frag.spv
/usr/bin/glslc ./shaders/simple_shader.vert -o ./shaders/simple_shader.vert.spv

cp ./shaders/*.spv ./cmake-build-debug/shaders/
