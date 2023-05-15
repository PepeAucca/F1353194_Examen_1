#include <stdint.h>



int main(void)
{
   //Puerto A
   //Direccion base:0x4001 0800
   //Modo puerto A:0x00 => 0x4001 0800
   //entrada de puerto A= 0x08 => 0x4001 0808
   uint32_t* puertoA_mode_reg =(uint32_t*) 0x40010800;
   uint32_t* puertoA_input_reg =(uint32_t*) 0x40010808;

   //Puerto B
   //Direccion base:0x4001 0C00
   //Modo puerto B:0x0C => 0x4001 0C0C
   //salida de puerto B= 0x04 => 0x4001 0C04
   uint32_t* puertoB_mode_reg =(uint32_t*) 0x40010C0C;
   uint32_t* puertoB_output_reg = (uint32_t*) 0x40010C04;

   //offset del reloj: 0x18
   //direccion base 0x4002 1000
   uint32_t* clk_reg = (uint32_t*) 0x40021018;

   *clk_reg |= (1 << 2);// abilita la señal de reloj del puerto A
   *clk_reg |= (1 << 3);// abilita la señal de reloj del puerto B

   //Configuracion entrada del puerto PA4 -> S1
   *puertoA_mode_reg &= 0xFFFF0FFF;//Linpiamos el puertA PA4
   *puertoA_mode_reg |= 0x00004000;


   //Configuracion entrada del puerto PA5 -> S2
   *puertoA_mode_reg &= 0xFFF0FFFF;//Linpiamos el puertA PA5
   *puertoA_mode_reg |= 0x00040000;

   //Configuracion salida del puerto PB3 -> D3
   *puertoB_mode_reg &= 0xFFFF0FFF;
   *puertoB_mode_reg |= 0x00002000;
   *puertoB_output_reg |= 0x00000008;

   //Configuracion salida del puerto PB4 -> D4
   *puertoB_mode_reg &= 0xFFF0FFFF;
   *puertoB_mode_reg |= 0x00020000;
   *puertoB_output_reg |= 0x0000010;

   int pulsaciones = 0;
   int parpadeos = 0;

   while(1)
   {
	   while((*puertoA_input_reg & 0x01) == 0);

	   while((*puertoA_input_reg & 0x01) == 1);

	   //Incrementar cantidad de pulsaciones
	   pulsaciones ++;
	   if (pulsaciones > 20)
	   {
		   pulsaciones = 0;
	   }

	   //Mostrar cantidad de parpadeos en D3
	   parpadeos = pulsaciones * 2;
	   for(int i = 0; i < parpadeos; i++)
	   {
		   for(int j = 0; j < 100000; j++);
		   *puertoB_output_reg |= 0x00000008;
		   for(int j = 0; j < 100000; j++);
		   *puertoB_output_reg &= 0xFFFFFFF7;
	   }

	   //Encender o apagar D4
	   if (pulsaciones % 2 == 0)
	   {
		   *puertoB_output_reg |= 0x0000010;
	   }
	   else
	   {
		   *puertoB_output_reg |= 0x00000E0;
	   }

   }


	for(;;);
}
