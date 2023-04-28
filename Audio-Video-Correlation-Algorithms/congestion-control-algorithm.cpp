//
//  congestion-control-algorithm.cpp
//  Audio-Video-Correlation-Algorithms
//
//  Created by kpa on 2023/4/28.
//

#include "congestion-control-algorithm.hpp"

using namespace::std;

// 模拟最大发送窗口
const int MAX_WINDOW_SIZE = 1024;

int congestion_control_algorithm() {
    std::cout << "拥塞控制算法 开始\n";
    // 当前发送窗口大小
    int window_size = 1;
    // 当前发送窗口中已发送的数据包个数
    int packets_sent = 0;
    // 当前已发送数据包的序列号
    int packet_number = 1;
    // 拥塞避免阈值
    int threshold = 64;
    // 上一次拥塞发生时的发送窗口大小
    int last_window_size = 1;
    // 上一次拥塞发生时的数据包序列号
    int last_packet_number = 0;
    
    while (true) {
            // 判断是否发生拥塞
            if (packets_sent > window_size) {
                // 发生拥塞，将发送窗口大小设置为拥塞避免阈值
                window_size = threshold;
                // 重新开始拥塞避免算法
                packets_sent = 0;
                // 更新拥塞避免阈值
                threshold = window_size / 2;
                // 记录上一次拥塞发生时的窗口大小和数据包序列号
                last_window_size = window_size;
                last_packet_number = packet_number;
                cout << "发生拥塞 新窗口大小: " << window_size << endl;
            }
            else {
                // 未发生拥塞，继续发送数据包
                packets_sent++;
                packet_number++;
                // 计算下一次发送窗口大小
                window_size = min(last_window_size + 1, MAX_WINDOW_SIZE);
                cout << "发送数据包, 窗口大小: " << window_size << endl;
            }
        // 模拟网络延迟
        std::this_thread::sleep_for(std::chrono::microseconds(100));
        }
    return 0;

}
