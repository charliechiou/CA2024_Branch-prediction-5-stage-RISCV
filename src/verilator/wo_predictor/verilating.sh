verilator PIPELINE.v --exe main.cpp --cc --Mdir PIPELINE --trace
make -C PIPELINE -f VPIPELINE.mk
echo "-------------------------------------"
echo "execution result"
./PIPELINE/VPIPELINE