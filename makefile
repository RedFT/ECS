GEDIT_GARBAGE=$(wildcard ./*~)
VIM_GARBAGE=$(wildcard ./.*.swp)


debug:
	`mkdir -p ./build/debug`
	cd build/debug && cmake ../.. -DDEBUG=1 -DCMAKE_BUILD_TYPE=Debug && make && cd ../..

release:
	`mkdir -p ./build/release`
	cd build/release && cmake ../.. -DDEBUG=0 -DCMAKE_BUILD_TYPE=Release && make && cd ../..

clean:
	rm -rf ./build/ ./ECS $(GEDIT_GARBAGE) $(VIM_GARBAGE)
	
