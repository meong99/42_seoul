/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_macos.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchae <mchae@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 17:40:13 by oouklich          #+#    #+#             */
/*   Updated: 2021/03/25 12:14:43 by mchae            ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_MACOS_H
# define KEY_MACOS_H

/*
** Keyboard LETTERS
*/

# define K_A 0
# define K_B 11
# define K_C 8
# define K_D 2
# define K_E 14
# define K_F 3
# define K_G 5
# define K_H 4
# define K_I 34
# define K_J 38
# define K_K 40
# define K_L 37
# define K_M 46
# define K_N 45
# define K_O 31
# define K_P 35
# define K_Q 12
# define K_R 15
# define K_S 1
# define K_T 17
# define K_U 32
# define K_V 9
# define K_W 13
# define K_X 7
# define K_Y 16
# define K_Z 6
# define K_SPACE 49
# define K_CTRL 256
# define K_SHIFT 257

/*
** Keyboard ARROWS
*/

# define K_AR_L 123
# define K_AR_R 124
# define K_AR_U 126
# define K_AR_D 125

/*
** Keyboard NUMPAD
*/

# define K_NP_DIV 75
# define K_NP_MUL 67
# define K_NP_MIN 78
# define K_NP_PLU 69
# define K_NP_1	83
# define K_NP_2	84
# define K_NP_3	85
# define K_NP_4	86
# define K_NP_5	87
# define K_NP_6	88
# define K_NP_7	89
# define K_NP_8	91
# define K_NP_9	92

/*
** Keyboard MISC
*/

# define K_SP 49
# define K_ESC 53
# define K_TAB 48

/*
** Mouse
*/

# define M_CLK_L 1
# define M_CLK_R 3
# define M_CLK_M 2
# define M_SCR_U 4
# define M_SCR_D 5

/*
** X11
*/

/*
** keybord
*/
# define KEYPRESS 2
# define KEYRELEASE 3
/*
** Pointer events
*/
# define BUTTONPRESS 4
# define BUTTONRELRESE 5
# define MOTIONNOTIFY 6
/*
** Window crossing events
*/
# define ENTERNOTIFY 7
# define LEAVENOTIFY 8
/*
** Input focus events
*/
# define FOCUSIN 9
# define FOCUSOUT 10
/*
** Keymap state notification event
*/
# define KEYMAPNOTIFY 11
/*
** Exposure events
*/
# define EXPOSE 12
# define GRAPHICSEXPOSE 13
# define NOEXPOSE 14
/*
** Structure control events
*/
# define CIRCULATEREQUEST 27
# define CONFIGUREREQUEST 23
# define MAPREQUEST 20
# define RESIZEREQUSET 25
/*
** color map
*/
# define COLORMAPNOTIFY 32
/*
** Client communication events
*/
# define PROPERTYNOTIFY 28
# define SELECTIONCLEAR 29
# define SELECTIONREQUSET 29
# define SELECTIONNOTIFT 29
# define CLIENTMASSAGE 33
/*
** window
*/
# define VISIBILITYNOTIFY 15
# define REPARENTNOTIFY 21
# define UNMAPNOTIFY 18
# define MAPPINGNOTIFY 34
# define MAPNOTIFY 19
# define GRAVITYNOTIFY 24
# define DESTROYNOTIFY 17
# define CREATENOTIFY 16
# define CONFIGURENOTIFY 22
# define CIRCULATENOTIFY 26

/*
** ??
*/
# define GENERICEVENT 35
# define LASTEVENT 36
#endif
