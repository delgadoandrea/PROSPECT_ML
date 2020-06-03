#include "test.h"
#include <cmath>

double test::Value(int index,double in0,double in1,double in2) {
   input0 = (in0 - 0.521776)/0.0425378;
   input1 = (in1 - 5.37405e+06)/5.99747e+06;
   input2 = (in2 - 4.8936)/21.5214;
   switch(index) {
     case 0:
         return neuron0x560d3f3cc9d0();
     default:
         return 0.;
   }
}

double test::Value(int index, double* input) {
   input0 = (input[0] - 0.521776)/0.0425378;
   input1 = (input[1] - 5.37405e+06)/5.99747e+06;
   input2 = (input[2] - 4.8936)/21.5214;
   switch(index) {
     case 0:
         return neuron0x560d3f3cc9d0();
     default:
         return 0.;
   }
}

double test::neuron0x560d3e92da60() {
   return input0;
}

double test::neuron0x560d3e928850() {
   return input1;
}

double test::neuron0x560d3ec27cb0() {
   return input2;
}

double test::input0x560d3e92b8d0() {
   double input = 5.57188;
   input += synapse0x560d3f3de1b0();
   input += synapse0x560d3f3cb960();
   input += synapse0x560d3f3de280();
   return input;
}

double test::neuron0x560d3e92b8d0() {
   double input = input0x560d3e92b8d0();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double test::input0x560d3ec07310() {
   double input = -0.0137871;
   input += synapse0x560d3f3de470();
   input += synapse0x560d3f3de4b0();
   input += synapse0x560d3f3de4f0();
   return input;
}

double test::neuron0x560d3ec07310() {
   double input = input0x560d3ec07310();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double test::input0x560d3e155100() {
   double input = -0.519098;
   input += synapse0x560d3f3cb1f0();
   input += synapse0x560d3f3cb230();
   input += synapse0x560d3f3cb270();
   return input;
}

double test::neuron0x560d3e155100() {
   double input = input0x560d3e155100();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double test::input0x560d3e8bab40() {
   double input = -4.83187;
   input += synapse0x560d3f3cb460();
   input += synapse0x560d3f3cb4a0();
   input += synapse0x560d3f3cb4e0();
   return input;
}

double test::neuron0x560d3e8bab40() {
   double input = input0x560d3e8bab40();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double test::input0x560d3f3cb520() {
   double input = 1.46219;
   input += synapse0x560d3f3cbc20();
   input += synapse0x560d3f3cbc60();
   input += synapse0x560d3f3cbca0();
   return input;
}

double test::neuron0x560d3f3cb520() {
   double input = input0x560d3f3cb520();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double test::input0x560d3f3cbce0() {
   double input = -1.49723;
   input += synapse0x560d3f3cc020();
   input += synapse0x560d3f3cc060();
   input += synapse0x560d3f3cc0a0();
   input += synapse0x560d3f3cc0e0();
   input += synapse0x560d3f3cc120();
   return input;
}

double test::neuron0x560d3f3cbce0() {
   double input = input0x560d3f3cbce0();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double test::input0x560d3f3cc160() {
   double input = -4.25882;
   input += synapse0x560d3f3cc410();
   input += synapse0x560d3f3cc450();
   input += synapse0x560d3f3cc490();
   input += synapse0x560d3f3cc4d0();
   input += synapse0x560d3f3cc510();
   return input;
}

double test::neuron0x560d3f3cc160() {
   double input = input0x560d3f3cc160();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double test::input0x560d3f3cc550() {
   double input = 3.93748;
   input += synapse0x560d3f3cc890();
   input += synapse0x560d3f3cc8d0();
   input += synapse0x560d3f3cc910();
   input += synapse0x560d3f3cc950();
   input += synapse0x560d3f3cc990();
   return input;
}

double test::neuron0x560d3f3cc550() {
   double input = input0x560d3f3cc550();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double test::input0x560d3f3cc9d0() {
   double input = -1.8225;
   input += synapse0x560d3f3ccd10();
   input += synapse0x560d3f3ccd50();
   input += synapse0x560d3f3ccd90();
   return input;
}

double test::neuron0x560d3f3cc9d0() {
   double input = input0x560d3f3cc9d0();
   return (input * 1)+0;
}

double test::synapse0x560d3f3de1b0() {
   return (neuron0x560d3e92da60()*-1.37563);
}

double test::synapse0x560d3f3cb960() {
   return (neuron0x560d3e928850()*10.0284);
}

double test::synapse0x560d3f3de280() {
   return (neuron0x560d3ec27cb0()*7.45109);
}

double test::synapse0x560d3f3de470() {
   return (neuron0x560d3e92da60()*-2.93355);
}

double test::synapse0x560d3f3de4b0() {
   return (neuron0x560d3e928850()*5.43753);
}

double test::synapse0x560d3f3de4f0() {
   return (neuron0x560d3ec27cb0()*0.158316);
}

double test::synapse0x560d3f3cb1f0() {
   return (neuron0x560d3e92da60()*-1.15947);
}

double test::synapse0x560d3f3cb230() {
   return (neuron0x560d3e928850()*0.674127);
}

double test::synapse0x560d3f3cb270() {
   return (neuron0x560d3ec27cb0()*-1.49321);
}

double test::synapse0x560d3f3cb460() {
   return (neuron0x560d3e92da60()*0.16453);
}

double test::synapse0x560d3f3cb4a0() {
   return (neuron0x560d3e928850()*-7.27787);
}

double test::synapse0x560d3f3cb4e0() {
   return (neuron0x560d3ec27cb0()*-6.06938);
}

double test::synapse0x560d3f3cbc20() {
   return (neuron0x560d3e92da60()*1.70743);
}

double test::synapse0x560d3f3cbc60() {
   return (neuron0x560d3e928850()*-5.64592);
}

double test::synapse0x560d3f3cbca0() {
   return (neuron0x560d3ec27cb0()*-0.115456);
}

double test::synapse0x560d3f3cc020() {
   return (neuron0x560d3e92b8d0()*-3.95029);
}

double test::synapse0x560d3f3cc060() {
   return (neuron0x560d3ec07310()*-1.41771);
}

double test::synapse0x560d3f3cc0a0() {
   return (neuron0x560d3e155100()*-1.79966);
}

double test::synapse0x560d3f3cc0e0() {
   return (neuron0x560d3e8bab40()*3.40912);
}

double test::synapse0x560d3f3cc120() {
   return (neuron0x560d3f3cb520()*-0.0752412);
}

double test::synapse0x560d3f3cc410() {
   return (neuron0x560d3e92b8d0()*-5.01027);
}

double test::synapse0x560d3f3cc450() {
   return (neuron0x560d3ec07310()*1.63511);
}

double test::synapse0x560d3f3cc490() {
   return (neuron0x560d3e155100()*1.72117);
}

double test::synapse0x560d3f3cc4d0() {
   return (neuron0x560d3e8bab40()*3.47907);
}

double test::synapse0x560d3f3cc510() {
   return (neuron0x560d3f3cb520()*-4.891);
}

double test::synapse0x560d3f3cc890() {
   return (neuron0x560d3e92b8d0()*5.92674);
}

double test::synapse0x560d3f3cc8d0() {
   return (neuron0x560d3ec07310()*2.02267);
}

double test::synapse0x560d3f3cc910() {
   return (neuron0x560d3e155100()*0.780332);
}

double test::synapse0x560d3f3cc950() {
   return (neuron0x560d3e8bab40()*-2.30561);
}

double test::synapse0x560d3f3cc990() {
   return (neuron0x560d3f3cb520()*0.739463);
}

double test::synapse0x560d3f3ccd10() {
   return (neuron0x560d3f3cbce0()*1.21485);
}

double test::synapse0x560d3f3ccd50() {
   return (neuron0x560d3f3cc160()*1.21729);
}

double test::synapse0x560d3f3ccd90() {
   return (neuron0x560d3f3cc550()*1.8229);
}

