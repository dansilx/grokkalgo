    //definição das frequências das notas musicais
    int NOTA_A = 444;
    int NOTA_C = 528;
    int NOTA_D = 592;
    int NOTA_E = 665;
    int NOTA_G = 791;

    //definição dos pinos dos LEDs
    int LED_VERMELHO = 7;
    int LED_VERDE = 12;
    int LED_AZUL = 11;
    int LED_AMARELO = 8;
    int LED_BRANCO = 13;
    int LED_RGB_R = A1;
    int LED_RGB_G = A2;
    int LED_RGB_B = A3;

    //definição dos pinos dos botões
    int BOTAO_AMARELO = 5;
    int BOTAO_AZUL = 4;
    int BOTAO_VERDE = 3;
    int BOTAO_VERMELHO = 6;
    int BOTAO_BRANCO = 2;
    int BOTAO_START = 14;

    //definições dos pinos do buzzer
    int BUZZER = 9;
    int BUZZER_ACTONE = 10;
    long buzzer_timer = 0;

    //define o momento do jogo em que se encontra
    // 0 - Aguardando inicio
    // 1 - Jogo em andamento, fase de sorteio
    // 2 - Jogo em andamento, aguardando input do usuário
    int GAME_TIME = 0;

    //define o round em que o jogo se encontra
    int GAME_ROUND = 0;

    //array que guarda todas as posições sorteadas para o jogo
    int game[200];

    void setup()
    {
    // inicia conexão serial
    Serial.begin(9600);
    
    //inicialização dos pinos dos LEDs
    pinMode(LED_VERMELHO, OUTPUT);
    pinMode(LED_VERDE, OUTPUT);
    pinMode(LED_AZUL, OUTPUT);
    pinMode(LED_AMARELO, OUTPUT);
    pinMode(LED_BRANCO, OUTPUT);
    
    //inicialização dos pinos do LED RGB
    pinMode(LED_RGB_R, OUTPUT);
    pinMode(LED_RGB_G, OUTPUT);
    pinMode(LED_RGB_B, OUTPUT);
    
    //desliga todos os LEDs
    digitalWrite(LED_VERMELHO, LOW);
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_AZUL, LOW);
    digitalWrite(LED_AMARELO, LOW);
    digitalWrite(LED_BRANCO, LOW);

    //inicialização dos pinos dos botões
    pinMode(BOTAO_VERMELHO,INPUT_PULLUP);
    pinMode(BOTAO_VERDE,INPUT_PULLUP);
    pinMode(BOTAO_AZUL,INPUT_PULLUP);
    pinMode(BOTAO_AMARELO,INPUT_PULLUP);
    pinMode(BOTAO_BRANCO,INPUT_PULLUP);
    
    pinMode(BOTAO_START,INPUT_PULLUP);

    //inicialização do pino do buzzer (som)
    pinMode(BUZZER,OUTPUT);
    
    delay(1000);
    
    //efeito de inicialização do jogo
    ledStartGame();
    
    
    }

    void loop()
    {
    //confere se o jogo ainda não foi inicializado
    if(GAME_TIME == 0)
    {
        //acende o LED RGB como branco indicando que o jogo está aguardando a inicialização
        acendeBranco();
        //verifica se o usuário apertou START para inicializar o jogo
        if(!digitalRead(BOTAO_START))
        {
        //iniciar o game no round 0
        GAME_ROUND = 0;
        //define uma seed para usar a função random();
        long seed = millis();
        //informa a seed a função random();
        randomSeed(seed);

        //faz o sorteio de todas as posições do jogo, máximo de 200 posições
        for(int i=0;i<200;i++)
        {
            game[i] = random(5);
            Serial.println(game[i]);
        }
        delay(1000);
        //define que o jogo começou
        GAME_TIME = 1;
        }

    }
    else
    {
        //confere se o jogo está na fase de sorteio
        if(GAME_TIME == 1)
        {
        //acende o LED RGB como amarelo para indicar que o jogo está em sorteio
        acendeAmarelo();
        //confere se o jogo não chegou ao limite
        if(GAME_ROUND<200)
        {
            //passa pro próximo round
            GAME_ROUND++;
            //pisca os leds e faz os sons até o round atual
            for(int i=0;i<GAME_ROUND;i++)
            {
            ativaLedTone(game[i]);
            delay(20);
            }
            //muda o jogo para a fase de input
            GAME_TIME = 2;
        }
        }
        //agora o jogo se encontra na fase de input do usuário
        else
        {
        //acende o LED RGB como azul indicando que o jogo está aguardando input do usuário
        acendeAzul();
        //variável que define se o usário errou ou acertou o input
        bool failed = false;
        //verifica se o jogo encontra-se com certeza na fase de input
        if(GAME_TIME == 2)
        {
            //variável que define qual momento do round o usuário se encontra
            int game_played = 0;
            //enquanto o momento do round não for igual ao round e o usuário não tiver falhado, continua lendo os inputs um a um
            while(game_played < GAME_ROUND && !failed)
            {
            //caso o usuário de input no botão vermelho
            if(!digitalRead(BOTAO_VERMELHO) && !failed && game_played<GAME_ROUND)
            {
                digitalWrite(LED_VERMELHO, HIGH);
                tone(BUZZER,NOTA_A);
                while(!digitalRead(BOTAO_VERMELHO))
                {
                delay(50);
                }
                delay(50);
                digitalWrite(LED_VERMELHO, LOW);
                noTone(BUZZER);
                if(game[game_played] == 0)
                {
                game_played++;
                }
                else
                {
                failed = true;
                }
                
            }
            
            //caso o usuário de input no botão Amarelo
            if(!digitalRead(BOTAO_AMARELO) && !failed && game_played<GAME_ROUND)
            {
                digitalWrite(LED_AMARELO, HIGH);
                tone(BUZZER,NOTA_C);
                while(!digitalRead(BOTAO_AMARELO))
                {
                delay(50);
                }
                delay(50);
                digitalWrite(LED_AMARELO, LOW);
                noTone(BUZZER);
                if(game[game_played] == 1)
                {
                game_played++;
                }
                else
                {
                failed = true;
                }
                
            }
            
            //caso o usuário de input no botão Azul
            if(!digitalRead(BOTAO_AZUL) && !failed && game_played<GAME_ROUND)
            {
                digitalWrite(LED_AZUL, HIGH);
                tone(BUZZER,NOTA_D);
                while(!digitalRead(BOTAO_AZUL))
                {
                delay(50);
                }
                delay(50);
                digitalWrite(LED_AZUL, LOW);
                noTone(BUZZER);
                if(game[game_played] == 2)
                {
                game_played++;
                }
                else
                {
                failed = true;
                }
                
            }
            
            //caso o usuário de input no botão Verde
            if(!digitalRead(BOTAO_VERDE) && !failed && game_played<GAME_ROUND)
            {
                digitalWrite(LED_VERDE, HIGH);
                tone(BUZZER,NOTA_E);
                while(!digitalRead(BOTAO_VERDE))
                {
                delay(50);
                }
                delay(50);
                digitalWrite(LED_VERDE, LOW);
                noTone(BUZZER);
                if(game[game_played] == 3)
                {
                game_played++;
                }
                else
                {
                failed = true;
                }
                
            }
            
            //caso o usuário de input no botão Branco
            if(!digitalRead(BOTAO_BRANCO) && !failed && game_played<GAME_ROUND)
            {
                digitalWrite(LED_BRANCO, HIGH);
                tone(BUZZER,NOTA_G);
                while(!digitalRead(BOTAO_BRANCO))
                {
                delay(50);
                }
                delay(50);
                digitalWrite(LED_BRANCO, LOW);
                noTone(BUZZER);
                if(game[game_played] == 4)
                {
                game_played++;
                }
                else
                {
                failed = true;
                }
                
            }
            }
            //verifica se o usuário falhou
            if(failed)
            {
            failedGame();
            }
            //caso ele não tenha falhado, passa pro próximo round
            else
            {
            acendeVerde();
            delay(250);
            piscaTodosLeds(3,150,150);
            delay(500);
            GAME_TIME = 1;
            }
        }
        }
    }
    }

    //função que pisca os leds e toca os sons para derrota
    void failedGame()
    {
    acendeVermelho();
    delay(250);
    digitalWrite(LED_VERMELHO, HIGH);
    digitalWrite(LED_VERDE, HIGH);
    digitalWrite(LED_AZUL, HIGH);
    digitalWrite(LED_AMARELO, HIGH);
    digitalWrite(LED_BRANCO, HIGH);
    delay(250);
    tone(BUZZER,444);
    delay(250);
    noTone(BUZZER);
    delay(20);
    tone(BUZZER,628);
    delay(250);
    noTone(BUZZER);
    delay(20);
    tone(BUZZER,592);
    delay(150);
    noTone(BUZZER);
    delay(20);
    tone(BUZZER,592);
    delay(150);
    noTone(BUZZER);
    delay(20);
    tone(BUZZER,592);
    delay(150);
    noTone(BUZZER);
    delay(20);
    tone(BUZZER,592);
    delay(150);
    noTone(BUZZER);
    delay(20);
    tone(BUZZER,592);
    delay(150);
    noTone(BUZZER);
    digitalWrite(LED_VERMELHO, LOW);
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_AZUL, LOW);
    digitalWrite(LED_AMARELO, LOW);
    digitalWrite(LED_BRANCO, LOW);
    delay(250);
    digitalWrite(LED_VERMELHO, HIGH);
    digitalWrite(LED_VERDE, HIGH);
    digitalWrite(LED_AZUL, HIGH);
    digitalWrite(LED_AMARELO, HIGH);
    digitalWrite(LED_BRANCO, HIGH);
    tone(BUZZER,444);
    delay(250);
    noTone(BUZZER);
    delay(20);
    tone(BUZZER,628);
    delay(250);
    noTone(BUZZER);
    delay(20);
    tone(BUZZER,592);
    delay(150);
    noTone(BUZZER);
    delay(20);
    tone(BUZZER,592);
    delay(150);
    noTone(BUZZER);
    delay(20);
    tone(BUZZER,592);
    delay(150);
    noTone(BUZZER);
    delay(20);
    tone(BUZZER,592);
    delay(150);
    noTone(BUZZER);
    delay(20);
    tone(BUZZER,592);
    delay(150);
    noTone(BUZZER);
    delay(20);
    digitalWrite(LED_VERMELHO, LOW);
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_AZUL, LOW);
    digitalWrite(LED_AMARELO, LOW);
    digitalWrite(LED_BRANCO, LOW);
    delay(250);
    
    
    piscaTodosLeds(1,250,250);

    GAME_TIME = 0;
    }

    //função que acende um led especifico junto do som referente a esse led
    void ativaLedTone(int num)
    {
    switch(num)
    {
        case 0: digitalWrite(LED_VERMELHO, HIGH);
                tone(BUZZER,NOTA_A);
                delay(250);
                digitalWrite(LED_VERMELHO, LOW);
                noTone(BUZZER);
                delay(20);
                break;
        case 1: digitalWrite(LED_AMARELO, HIGH);
                tone(BUZZER,NOTA_C);
                delay(250);
                digitalWrite(LED_AMARELO, LOW);
                noTone(BUZZER);
                delay(20);
                break;
        case 2: digitalWrite(LED_AZUL, HIGH);
                tone(BUZZER,NOTA_D);
                delay(250);
                digitalWrite(LED_AZUL, LOW);
                noTone(BUZZER);
                delay(20);
                break;
        case 3: digitalWrite(LED_VERDE, HIGH);
                tone(BUZZER,NOTA_E);
                delay(250);
                digitalWrite(LED_VERDE, LOW);
                noTone(BUZZER);
                delay(20);
                break;
        case 4: digitalWrite(LED_BRANCO, HIGH);
                tone(BUZZER,NOTA_G);
                delay(250);
                digitalWrite(LED_BRANCO, LOW);
                noTone(BUZZER);
                delay(20);
                break;
        
    }
    }

    //função que acende os leds por um determinado tempo
    void ledAcendeTodos(int time)
    {
    digitalWrite(LED_VERMELHO, HIGH);
    digitalWrite(LED_VERDE, HIGH);
    digitalWrite(LED_AZUL, HIGH);
    digitalWrite(LED_AMARELO, HIGH);
    digitalWrite(LED_BRANCO, HIGH);
    delay(time);
    digitalWrite(LED_VERMELHO, LOW);
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_AZUL, LOW);
    digitalWrite(LED_AMARELO, LOW);
    digitalWrite(LED_BRANCO, LOW);
    }

    //função que pisca os leds
    void piscaTodosLeds(int vezes, int aceso, int apagado)
    {
    for(int i=0; i<vezes; i++)
    {
        ledAcendeTodos(aceso);
        delay(apagado);
    }
    }
    
    ////função que pisca os leds e toca os sons para iniciar o jogo
    void ledStartGame()
    {
    acendeVermelho();
    digitalWrite(LED_VERMELHO, HIGH);
    tone(BUZZER,NOTA_A);
    delay(250);
    digitalWrite(LED_VERMELHO, LOW);
    noTone(BUZZER);
    delay(20);
    
    acendeAmarelo();
    digitalWrite(LED_AMARELO, HIGH);
    tone(BUZZER,NOTA_C);
    delay(250);
    digitalWrite(LED_AMARELO, LOW);
    noTone(BUZZER);
    delay(20);
    
    acendeAzul();
    digitalWrite(LED_AZUL, HIGH);
    tone(BUZZER,NOTA_D);
    delay(250);
    digitalWrite(LED_AZUL, LOW);
    noTone(BUZZER);
    delay(20);
    
    acendeVerde();
    digitalWrite(LED_VERDE, HIGH);
    tone(BUZZER,NOTA_E);
    delay(250);
    digitalWrite(LED_VERDE, LOW);
    noTone(BUZZER);
    delay(20);
    
    acendeBranco();
    digitalWrite(LED_BRANCO, HIGH);
    tone(BUZZER,NOTA_G);
    delay(250);
    digitalWrite(LED_BRANCO, LOW);
    noTone(BUZZER);
    delay(20);
    
    acendeVerde();
    digitalWrite(LED_VERDE, HIGH);
    tone(BUZZER,NOTA_E);
    delay(250);
    digitalWrite(LED_VERDE, LOW);
    noTone(BUZZER);
    delay(20);
    
    acendeAzul();
    digitalWrite(LED_AZUL, HIGH);
    tone(BUZZER,NOTA_D);
    delay(250);
    digitalWrite(LED_AZUL, LOW);
    noTone(BUZZER);
    delay(20);
    
    acendeAmarelo();
    digitalWrite(LED_AMARELO, HIGH);
    tone(BUZZER,NOTA_C);
    delay(250);
    digitalWrite(LED_AMARELO, LOW);
    noTone(BUZZER);
    delay(20);
    
    
    acendeVermelho();
    digitalWrite(LED_VERMELHO, HIGH);
    tone(BUZZER,NOTA_A);
    delay(250);
    digitalWrite(LED_VERMELHO, LOW);
    noTone(BUZZER);
    apaga();
    
    delay(500);
    
    digitalWrite(LED_BRANCO, HIGH);
    digitalWrite(LED_VERMELHO, HIGH);
    digitalWrite(LED_VERDE, HIGH);
    digitalWrite(LED_AZUL, HIGH);
    digitalWrite(LED_AMARELO, HIGH);
    
    acendeVermelho();
    delay(100);
    acendeAmarelo();
    delay(100);
    acendeAzul();
    delay(100);
    acendeVerde();
    delay(100);
    acendeBranco();
    delay(100);
    
    digitalWrite(LED_VERMELHO, LOW);
    digitalWrite(LED_VERDE, LOW);
    digitalWrite(LED_AZUL, LOW);
    digitalWrite(LED_AMARELO, LOW);
    digitalWrite(LED_BRANCO, LOW);
    apaga();

    }


    //FUNÇÕES LED RGB

    void acendeVermelho(){
    digitalWrite(LED_RGB_B, LOW);
    digitalWrite(LED_RGB_G, LOW);
    digitalWrite(LED_RGB_R, HIGH);
    }
    void acendeAzul(){
    digitalWrite(LED_RGB_B, HIGH);
    digitalWrite(LED_RGB_G, LOW);
    digitalWrite(LED_RGB_R, LOW);
    }
    void acendeVerde(){
    digitalWrite(LED_RGB_B, LOW);
    digitalWrite(LED_RGB_G, HIGH);
    digitalWrite(LED_RGB_R, LOW);
    }
    void acendeAmarelo(){
    analogWrite(LED_RGB_B, 0);
    analogWrite(LED_RGB_G, 255);
    analogWrite(LED_RGB_R, 255);
    }
    void acendeRoxo(){
    analogWrite(LED_RGB_B, 207);
    analogWrite(LED_RGB_G, 0);
    analogWrite(LED_RGB_R, 255);
    }
    void acendeBranco(){
    digitalWrite(LED_RGB_B, HIGH);
    digitalWrite(LED_RGB_G, HIGH);
    digitalWrite(LED_RGB_R, HIGH);
    }

    void apaga()
    {
    digitalWrite(LED_RGB_B, LOW);
    digitalWrite(LED_RGB_G, LOW);
    digitalWrite(LED_RGB_R, LOW);
    }
    


