/*
 * File:   main.c
 * Author: johan
 *
 * Created on 3 de Junho de 2021, 13:58
 */


#define F_CPU 16000000      //define a frequencia do uC para 16MHz
#include <avr/io.h>         //Biblioteca geral dos AVR
#include <avr/interrupt.h>  //Biblioteca de interrup��o
#include <stdio.h>          //Bilioteca do C
#include <util/delay.h>     //Biblioteca geradora de atraso
#include "UART.h"           //Biblioteca da comunica��o UART

//vari�veis de comando para os registradores
#define set_bit(y,bit) (y|=(1<<bit)) //coloca em 1 o bit x da vari�vel Y
#define clr_bit(y,bit) (y&=~(1<<bit)) //coloca em 0 o bit x da vari�vel Y
#define cpl_bit(y,bit) (y^=(1<<bit)) //troca o estado l�gico do bit x da vari�vel Y
#define tst_bit(y,bit) (y&(1<<bit)) //retorna 0 ou 1 conforme leitura do bit


#define AIN1    PD5 //configura��es das conex�es do Agostinho/ Van Grogue
#define AIN2    PD6

#define BIN1    PD4
#define BIN2    PD3
//=======================//
/*
#define AIN1    PB2 //configura��es das conex�es do Celta Caindo
#define AIN2    PB1

#define BIN1    PB0
#define BIN2    PD5*/
//============================//



int main(void) {
    DDRB =  0b11111111;     //define o PORTB como sa�da
    PORTB = 0b00000000;     //Inicializa todos em 0
    DDRD =  0b11111111;     //define o PORTD como sa�da
    PORTD = 0b00000000;     //Inicializa todos em 0
    
    
    while (1) {
        clr_bit(PORTD, AIN1);
        set_bit(PORTD, AIN2);       //frente direita
        set_bit(PORTD, BIN1);       //frente esquerda
        clr_bit(PORTD, BIN2);
        
        _delay_ms(500);
        
        clr_bit(PORTD, AIN1);
        clr_bit(PORTD, AIN2);       //frente direita
        clr_bit(PORTD, BIN1);       //frente esquerda
        clr_bit(PORTD, BIN2);
        
        //=============================//
        //Configura��es do Celta//
        /*
        clr_bit(PORTB, AIN1);
        set_bit(PORTB, AIN2);       //frente direita
        set_bit(PORTB, BIN1);       //frente esquerda
        clr_bit(PORTD, BIN2);
        
        _delay_ms(500);
        
        clr_bit(PORTB, AIN1);
        clr_bit(PORTB, AIN2);       //frente direita
        clr_bit(PORTB, BIN1);       //frente esquerda
        clr_bit(PORTD, BIN2);*/
    }
}
