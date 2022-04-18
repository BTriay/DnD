import <string>;
import <iostream>;
import <fstream>;

import Logger;

int main()
{
    Logger logger{ "dnd.logs" };
    logger.info("this is a log");
}