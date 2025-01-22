verilator CPU.v --exe main.cpp --cc --Mdir CPU --trace
make -C CPU -f VCPU.mk
echo "-------------------------------------"
echo "execution result"
./CPU/VCPU